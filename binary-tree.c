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

static void destroy_branch(t_node *node) {
    if (node == NULL) {
        return;
    }

    destroy_branch(node->left);
    destroy_branch(node->right);

    free(node);
}

void destroy_tree(t_tree *tree) {
    if (tree == NULL) {
        return;
    }

    destroy_branch(tree->root);

    free(tree);
}

int is_empty(t_tree *tree) {
    return tree == NULL || tree->root == NULL;
}

int insert_root(t_tree *tree, char item) {
    if (tree == NULL || !is_empty(tree)) {
        return 0;
    }

    t_node *root = create_node(item);

    if (root == NULL) {
        return 0;
    }

    tree->root = root;

    return 1;
}

int insert_left(t_node *parent, char item) {
    if (parent == NULL || parent->left != NULL) {
        return 0;
    }

    t_node *node = create_node(item);

    if (node == NULL) {
        return 0;
    }

    parent->left = node;

    return 1;
}
