#include <stdio.h>
#include <stdlib.h>

typedef struct list_node *list_pointer;
typedef struct list_node { 
    int data; 
    list_pointer link; 
} list_node;

// head 노드가 있는 list 생성
list_pointer create_sorted_list();
// head list의 적절한 위치에 data 삽입
void sorted_list_insert(list_pointer head, int data);
// head list에서 가장 작은 data 노드를 삭제하고 data 반환
int sorted_list_deletemin(list_pointer head);

int main() {
    list_pointer head = create_sorted_list();

    sorted_list_insert(head, 4);
    sorted_list_insert(head, 1);
    sorted_list_insert(head, 6);

    int next = sorted_list_deletemin(head);
    printf("%d\n", next);

    return 0;
}

list_pointer create_sorted_list() {
    list_pointer head = (list_pointer) malloc(sizeof(list_node));
    head->link = NULL;
    return head;
}

void sorted_list_insert(list_pointer head, int data) {
    list_pointer node = (list_pointer) malloc(sizeof(list_node));
    node->data = data;

    list_pointer prev = head;
    list_pointer curr = head->link;
    while (curr != NULL && curr->data < data) {
        prev = curr;
        curr = curr->link;
    }

    prev->link = node;
    node->link = curr;
}

int sorted_list_deletemin(list_pointer head) {
    list_pointer node = head->link;
    head->link = node->link;
    int data = node->data;
    free(node);
    return data;
}
