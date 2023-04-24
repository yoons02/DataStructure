#include <stdio.h>
#include <stdlib.h>

typedef struct node* node_ptr;
typedef struct node {
    node_ptr l_link;
    node_ptr r_link;
    int page;
} node;

node dummy_head;
node_ptr current_page = &dummy_head;

void follow(int x) {
    // 현재 페이지의 오른쪽 노드들을 모두 삭제
    while (current_page->r_link != NULL) {
        node_ptr temp = current_page->r_link;
        current_page->r_link = temp->r_link;
        free(temp);
    }

    // 새로운 노드 삽입
    node_ptr new_node = (node_ptr)malloc(sizeof(node));
    new_node->page = x;
    new_node->r_link = NULL;
    new_node->l_link = current_page;
    current_page->r_link = new_node;

    // current_page 업데이트
    current_page = new_node;

    printf("%d\n", current_page->page);
}

void back() {
    if (current_page->l_link != NULL) {
        // current_page 업데이트
        current_page = current_page->l_link;
        printf("%d\n", current_page->page);
    }
}

void forward() {
    if (current_page->r_link != NULL) {
        // current_page 업데이트
        current_page = current_page->r_link;
        printf("%d\n", current_page->page);
    }
}

int main() {
    // 초기화
    dummy_head.l_link = NULL;
    dummy_head.r_link = NULL;
    dummy_head.page = -1;

    // 작업 테스트
    follow(100);
    follow(200);
    follow(300);
    back();
    follow(400);
    follow(500);
    back();
    back();
    forward();

    return 0;
}
