#ifndef STACK_H
#define STACK_H

#include "binary_tree.h"

typedef struct _stack t_stack;

t_stack* create_stack();
int push(t_stack*, t_node*);
int pop(t_stack*, t_node**);
int top(t_stack*, t_node**);
void destroy_stack(t_stack*);
int is_stack_empty(t_stack*);

#endif
