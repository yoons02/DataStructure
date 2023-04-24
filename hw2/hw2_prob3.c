#include <stdio.h>
#include <stdlib.h>

typedef struct node *list_pointer;
typedef struct node {
    int data;
    list_pointer link;
} list_node;

void merge(list_pointer head1, list_pointer head2) {
    list_pointer p1 = head1->link;
    list_pointer p2 = head2->link;
    list_pointer new_head = head1;
    list_pointer p = new_head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            p->link = p1;
            p1 = p1->link;
        }
        else {
            p->link = p2;
            p2 = p2->link;
        }
        p = p->link;
    }

    if (p1 != NULL) {
        p->link = p1;
    }
    else {
        p->link = p2;
    }
    free(head2);
}

int main() {
    list_pointer head1 = (list_pointer) malloc(sizeof(list_node));
    list_pointer head2 = (list_pointer) malloc(sizeof(list_node));
    head1->link = NULL;
    head2->link = NULL;

    // 리스트1 초기화
    list_pointer p = head1;
    for (int i = 1; i <= 5; i++) {
        list_pointer temp = (list_pointer) malloc(sizeof(list_node));
        temp->data = i * 2;
        temp->link = NULL;
        p->link = temp;
        p = p->link;
    }

    // 리스트2 초기화
    p = head2;
    for (int i = 1; i <= 4; i++) {
        list_pointer temp = (list_pointer) malloc(sizeof(list_node));
        temp->data = i * 3;
        temp->link = NULL;
        p->link = temp;
        p = p->link;
    }

    // 리스트1 출력
    printf("List 1: ");
    p = head1->link;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");

    // 리스트2 출력
    printf("List 2: ");
    p = head2->link;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");

    // 리스트 합병
    merge(head1, head2);

    // 합병된 리스트 출력
    printf("Merged list: ");
    p = head1->link;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->link;
    }
    printf("\n");

    // 동적 할당 해제
    p = head1;
    while (p != NULL) {
        list_pointer temp = p;
        p = p->link;
        free(temp);
    }

    return 0;
}
