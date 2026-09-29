#include<stdio.h>
#include<stdlib.h>
#include"binary-tree.h"

void menu() {
    printf("-----------------------------------------------\n");
    printf("Select a function:\n");
    printf(" 1 - insert_root\n");
    printf(" 2 - insert_left\n");
    printf(" 3 - insert_right\n");
    printf(" 4 - height\n");
    printf(" 5 - total_nodes\n");
    printf(" 6 - search\n");
    printf(" 7 - remove_node\n");
    printf(" 8 - is_empty\n");
    printf(" 9 - pre_order\n");
    printf("10 - in_order\n");
    printf("11 - post_order\n");
    printf("12 - exit\n");
    printf("-----------------------------------------------\n");
    printf("Your choice: ");
}

int main() {
    t_tree *tree = create_tree();

    int opt = 0;
    do {
        menu();
        scanf("%d", &opt);

        switch (opt) {
            case 1: {
                printf("-----------------------------------------------\n");

                char item;

                printf("Insert the root value: ");
                scanf("%c", &item); 
                
                insert_root(tree, item);

                break;
            }
            default:
                break;
        }
    } while (opt != 12);

    destroy_tree(tree);

    return 0;
}
