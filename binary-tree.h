#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _node {
    char item;
    struct _node *left;
    struct _node *right;
} t_node;

typedef struct {
    t_node *root;
} t_tree;

t_tree* create_tree();
t_node* create_node(char);
void destroy_tree(t_tree*);
int is_empty(t_tree*);

#endif