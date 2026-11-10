#ifndef QUEUE_H
#define QUEUE_H

#include "binary_tree.h"

typedef struct _queue t_queue;

t_queue* create_queue();
int in(t_queue*, t_node*);
int out(t_queue*, t_node**);
int is_queue_empty(t_queue*);
void destroy_queue(t_queue*);

#endif
