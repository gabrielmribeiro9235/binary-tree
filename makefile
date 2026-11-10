CC = gcc
CFLAGS = -Wall -Wextra -I. -Ilibs

ifeq ($(OS),Windows_NT)
    PLATFORM = windows
    TARGET   = my_program.exe
    ifneq (,$(findstring cmd,$(shell echo %COMSPEC%)))
        RM = del /Q /F
    else
        RM = rm -f
    endif
else
    PLATFORM = linux
    TARGET   = my_program
    RM       = rm -f
endif

LDFLAGS = -Llibs
LDLIBS  = -lstack_$(PLATFORM) -lqueue_$(PLATFORM)

OBJS = main.o binary_tree.o
HEADERS = binary_tree.h libs/stack.h libs/queue.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) $(LDLIBS)

main.o: main.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o main.o main.c

binary_tree.o: binary_tree.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o binary_tree.o binary_tree.c

clean:
	-$(RM) $(TARGET) $(OBJS)

.PHONY: all clean