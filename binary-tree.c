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

int insert_right(t_node *parent, char item) {
    if (parent == NULL || parent->right != NULL) {
        return 0;
    }

    t_node *node = create_node(item);

    if (node == NULL) {
        return 0;
    }

    parent->right = node;

    return 1;
}

static int remove_node_recursive(t_node **root, t_node *target) {
    if (*root == NULL) {
        return 0;
    }

    if (*root == target) {
        destroy_branch(*root);
        *root = NULL;
        return 1;
    }

    return remove_node_recursive(&((*root)->left), target) || remove_node_recursive(&((*root)->right), target);
}

int remove_node(t_tree *tree, t_node *node) {
    if (tree == NULL || tree->root == NULL || node == NULL) {
        return 0;
    }

    return remove_node_recursive(&(tree->root), node);
}

int height(t_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    }

    t_tree left, right;
    left.root = tree->root->left;
    right.root = tree->root->right;
    int a = 1 + height(&left);
    int b = 1 + height(&right);

    if (a > b) {
        return a;
    }

    return b;
}

int total_nodes(t_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    }

    t_tree left, right;
    left.root = tree->root->left;
    right.root = tree->root->right;

    return 1 + total_nodes(&left) + total_nodes(&right);
}
