#include <stdio.h>
#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void addq(struct Queue *q, int value) {
    if (q->rear == MAX_SIZE - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int deleteq(struct Queue *q) {
    int item;
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
    }
    return item;
}

void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1)
        printf("Stack is full\n");
    else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(struct Stack *s) {
    int item;
    if (s->top == -1) {
        printf("Stack is empty\n");
        item = -1;
    } else {
        item = s->items[s->top];
        s->top--;
    }
    return item;
}

void reverseQueue(struct Queue *q) {
    struct Stack s;
    s.top = -1;

    // Queue의 모든 요소를 Stack으로 이동
    while (q->front <= q->rear) {
        push(&s, deleteq(q));
    }

    // Stack의 모든 요소를 Queue로 이동
    while (s.top >= 0) {
        addq(q, pop(&s));
    }
}

int main() {
    struct Queue q;
    q.front = -1;
    q.rear = -1;

    struct Stack s;
    s.top = -1;

    // Queue에 요소 추가
    addq(&q, 1);
    addq(&q, 2);
    addq(&q, 3);
    addq(&q, 4);
    addq(&q, 5);

    printf("Before reverse: ");
    // 변경 전 Queue 출력
    int i;
    for (i = q.front; i <= q.rear; i++) {
        printf("%d ", q.items[i]);
    }

    // Queue의 모든 요소를 Stack으로 이동
    while (q.front <= q.rear) {
        push(&s, deleteq(&q));
    }

    // Stack의 모든 요소를 Queue로 이동
    while (s.top >= 0) {
        addq(&q, pop(&s));
    }

    printf("\nAfter reverse: ");
    // 변경 후 Queue 출력
    while (q.front <= q.rear) {
        printf("%d ", deleteq(&q));
    }

    return 0;
}
