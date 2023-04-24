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

struct Queue {
    struct Point arr[100];
    int front, rear;
};

void initQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

void addq(struct Queue *queue, int x, int y) {
    if (maze[x][y] == 1 || visited[x][y] == 1) return; // 벽이거나 이미 방문한 곳이면 addq하지 않음
    queue->rear++;
    queue->arr[queue->rear].x = x;
    queue->arr[queue->rear].y = y;
    visited[x][y] = 1; // 방문 체크
}

void deleteq(struct Queue *queue) {
    if (queue->front == queue->rear) return; // 큐가 비어있으면 deleteq하지 않음
    queue->front++;
}

struct Point peek(struct Queue *queue) {
    return queue->arr[queue->front + 1];
}

int isEmpty(struct Queue *queue) {
    return queue->front == queue->rear;
}

void printQueue(struct Queue *queue) {
    for (int i = queue->front + 1; i <= queue->rear; i++) {
        printf("(%d, %d) ", queue->arr[i].x, queue->arr[i].y);
    }
    printf("\n");
}

void BFS(int startX, int startY, int endX, int endY) {
    struct Queue q;
    initQueue(&q);
    addq(&q, startX, startY); // 시작점 addq

    while (!isEmpty(&q)) {
        struct Point current = peek(&q); // 큐에서 현재 위치 peek
        deleteq(&q); // 큐에서 현재 위치 deleteq

        if (current.x == endX && current.y == endY) {
            printf("도착점을 찾았습니다.\n");
            return;
        }

        // 상하좌우 이동
        if (current.x - 1 >= 0) addq(&q, current.x - 1, current.y); // 상
        if (current.x + 1 < ROW) addq(&q, current.x + 1, current.y); // 하
        if (current.y + 1 < COL) addq(&q, current.x, current.y + 1); // 우
        if (current.y - 1 >= 0) addq(&q, current.x, current.y - 1); // 좌

        printf("탐색 위치: (%d, %d)\n", current.x, current.y);
    }

    printf("도착점을 찾을 수 없습니다.\n");
}


int main() {
    BFS(1, 0, 2, 4);
    return 0;
}
