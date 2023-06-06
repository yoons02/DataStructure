#include "bst_tf.h"

int main() {
    // 이진 트리 구조체와 값을 초기화합니다.
    Node node1 = {4, NULL, NULL};
    Node node2 = {2, NULL, NULL};
    Node node3 = {6, NULL, NULL};
    Node node4 = {1, NULL, NULL};
    Node node5 = {3, NULL, NULL};
    Node node6 = {5, NULL, NULL};
    Node node7 = {7, NULL, NULL};

    node1.left_child = &node2;
    node1.right_child = &node3;
    node2.left_child = &node4;
    node2.right_child = &node5;
    node3.left_child = &node6;
    node3.right_child = &node7;

    // IsBST 함수를 호출하여 이진 트리가 BST인지 확인합니다.
    int result = IsBST(&node1, INT_MIN, INT_MAX);

    // 결과 출력
    if (result) {
        printf("Given binary tree is a BST.\n");
    } else {
        printf("Given binary tree is not a BST.\n");
    }

    return 0;
}


int IsBST(tree_pointer t, int MIN, int MAX) {
    if (t == NULL) {
        return 1;  // 빈 트리는 BST입니다.
    }

    if (t->key < MIN || t->key > MAX) {
        return 0;  // 현재 노드의 키 값이 범위를 벗어나면 BST가 아닙니다.
    }

    // 좌측 서브트리와 우측 서브트리도 BST인지 확인합니다.
    int left_bst = IsBST(t->left_child, MIN, t->key - 1);
    int right_bst = IsBST(t->right_child, t->key + 1, MAX);

    return (left_bst && right_bst);
}