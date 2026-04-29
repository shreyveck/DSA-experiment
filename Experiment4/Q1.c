#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

struct Queue {
    int arr[SIZE];
    int front;
    int rear;
};

void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q) {
    return (q->rear == SIZE - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("\n[ERROR] Queue Overflow!\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;

    printf("\n[INFO] %d inserted into queue\n", value);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\n[ERROR] Queue Underflow!\n");
        return;
    }

    printf("\n[INFO] %d removed from queue\n", q->arr[q->front]);
    q->front++;
}

void peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\n[INFO] Queue is Empty\n");
        return;
    }

    printf("\n[INFO] Front Element: %d\n", q->arr[q->front]);
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\n[INFO] Queue is Empty\n");
        return;
    }

    printf("\nQueue Elements:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initialize(&q);

    int choice, value;

    while (1) {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                peek(&q);
                break;

            case 4:
                display(&q);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}
