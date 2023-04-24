#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {1, 0, 1, 0, 1},
    {2, 0, 1, 0, 1},
    {1, 0, 0, 0, 3},
    {1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1}
}; // 1은 벽, 0은 길, 2는 출발점, 3은 도착점

int visited[ROW][COL] = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
}; // 방문한 위치를 표시하는 배열

struct Point {
    int x, y;
};

struct Stack {
    struct Point arr[100];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, int x, int y) {
    if (maze[x][y] == 1 || visited[x][y] == 1) return; // 벽이거나 이미 방문한 곳이면 push하지 않음
    stack->top++;
    stack->arr[stack->top].x = x;
    stack->arr[stack->top].y = y;
    visited[x][y] = 1; // 방문 체크
    printf("탐색 위치: (%d, %d)\n", x, y); // 추가된 부분
}


void pop(struct Stack *stack) {
    stack->top--;
}

struct Point peek(struct Stack *stack) {
    return stack->arr[stack->top];
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void printStack(struct Stack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("(%d, %d) ", stack->arr[i].x, stack->arr[i].y);
    }
    printf("\n");
}

void DFS(int startX, int startY, int endX, int endY) {
    struct Stack s;
    initStack(&s);
    push(&s, startX, startY); // 시작점 push

    while (!isEmpty(&s)) {
        struct Point current = peek(&s); // 스택에서 현재 위치 pop
        pop(&s);
        int x = current.x;
        int y = current.y;

        if (x == endX && y == endY) {
            printf("도착점을 찾았습니다.\n");
            return;
        }

        // 가능한 위치들 스택에 push
        if (y > 0) push(&s, x, y - 1); // left
        if (y < COL - 1) push(&s, x, y + 1); // right
        if (x < ROW - 1) push(&s, x + 1, y); // down
        if (x > 0) push(&s, x - 1, y); // up
    }

    printf("도착점을 찾을 수 없습니다.\n");
}

int main() {
    // 시작점 (1, 1), 도착점 (4, 4)
    DFS(1, 0, 2, 4);

    return 0;
}
