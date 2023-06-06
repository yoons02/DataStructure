#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct node *tree_pointer;
typedef struct node {
    int key;
    tree_pointer left_child;
    tree_pointer right_child;
} Node;

int IsBST(tree_pointer t, int MIN, int MAX);