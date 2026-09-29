CC = gcc
CFLAGS = -Wall -Wextra

all = my_program

my_program: main.o binary-tree.o
	  $(CC) $(CFLAGS) -o my_program main.o binary-tree.o

main.o: main.c binary-tree.h
	  $(CC) $(CFLAGS) -c -o main.o main.c

binary-tree.o: binary-tree.c binary-tree.h
	  $(CC) $(CFLAGS) -c -o binary-tree.o binary-tree.c

clean:
	  rm -f my_program main.o binary-tree.o