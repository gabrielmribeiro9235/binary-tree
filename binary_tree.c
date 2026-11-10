#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"
#include"./libs/stack.h"
#include"./libs/queue.h"

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

t_node* search(t_node *root, char item) {
    if (root == NULL) {
        return NULL;
    }

    if (root->item == item) {
        return root;
    }

    t_node *left_search = search(root->left, item);

    if (left_search != NULL) {
        return left_search;
    }

    return search(root->right, item);
}

void pre_order(t_node *root) {
    if (root == NULL) {
        return;
    }

    printf("%c ", root->item);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(t_node *root) {
    if (root == NULL) {
        return;
    }

    in_order(root->left);
    printf("%c ", root->item);
    in_order(root->right);
}

void post_order(t_node *root) {
    if (root == NULL) {
        return;
    }

    post_order(root->left);
    post_order(root->right);
    printf("%c ", root->item);
}

void width_traversal(t_tree *tree) {
    if (is_empty(tree)) {
        return;
    }

    t_queue *queue = create_queue();

    if (queue == NULL) {
        return;
    }

    t_node *current = tree->root;
    in(queue, current);

    while (!is_queue_empty(queue)) {
        out(queue, &current);

        printf("%c ", current->item);

        if (current->left != NULL) {
            in(queue, current->left);
        }
        if (current->right != NULL) {
            in(queue, current->right);
        }
    }

    printf("\n");
    destroy_queue(queue);
}

void iterative_pre_order(t_node *root) {
    if (root == NULL) {
        return;
    }

    t_stack *stack = create_stack();

    if (stack == NULL) {
        return;
    }

    push(stack, root);

    while (!is_stack_empty(stack)) {
        t_node *current;
        pop(stack, &current);

        printf("%c ", current->item);

        if (current->right != NULL) {
            push(stack, current->right);
        }
        if (current->left != NULL) {
            push(stack, current->left);
        }
    }

    destroy_stack(stack);
}

void iterative_in_order(t_node *root) {
    if (root == NULL) {
        return;
    }

    t_stack *stack = create_stack();

    if (stack == NULL) {
        return;
    }

    t_node *current = root;
    int visited = 0;
    while(current != NULL || !is_stack_empty(stack)) {
        if (current->left != NULL && !visited) {
            push(stack, current);
            current = current->left;
        } else if (current->right != NULL) {
            printf("%c ", current->item);
            current = current->right;
            visited = 0;
        } else {
            printf("%c ", current->item);
            if (pop(stack, &current)) {
                visited = 1;
            } else {
                current = NULL;
            }
        }
    }

    destroy_stack(stack);
}
