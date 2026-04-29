#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue {
    int arr[SIZE];
    int front, rear;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front > q->rear);
}

void enqueue(struct Queue *q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(struct Queue *q) {
    return q->arr[q->front++];
}

// Stack operations
struct Queue q1, q2;

void push(int x) {
    enqueue(&q2, x);

    while (!isEmpty(&q1)) {
        enqueue(&q2, dequeue(&q1));
    }

    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;

    q2.front = 0;
    q2.rear = -1;
}

void pop() {
    if (isEmpty(&q1)) {
        printf("Stack Empty\n");
        return;
    }
    printf("Popped: %d\n", dequeue(&q1));
}

void peek() {
    if (isEmpty(&q1)) {
        printf("Stack Empty\n");
        return;
    }
    printf("Top: %d\n", q1.arr[q1.front]);
}

void display() {
    for (int i = q1.front; i <= q1.rear; i++) {
        printf("%d ", q1.arr[i]);
    }
    printf("\n");
}

int main() {
    init(&q1);
    init(&q2);

    int ch, val;

    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
        }
    }
}
