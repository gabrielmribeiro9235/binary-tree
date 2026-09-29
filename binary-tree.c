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