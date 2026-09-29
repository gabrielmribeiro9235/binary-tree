#include<stdio.h>
#include<stdlib.h>
#include"binary-tree.h"

t_tree* create_tree() {
    t_tree *tree = malloc(sizeof(t_tree));

    if (tree == NULL) {
        exit(1);
    }

    tree->root = NULL;

    return tree;    
}


t_node* create_node(char item) {
    t_node *node = malloc(sizeof(t_node));

    if (node == NULL) {
        return NULL;
    }

    node->item = item;
    node->left = NULL;
    node->right = NULL;

    return node;
}