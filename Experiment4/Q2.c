#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void initialize(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return (q->front == NULL);
}

void enqueue(struct Queue *q, int value) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }

    printf("\nInserted: %d\n", value);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Underflow\n");
        return;
    }

    struct Node *temp = q->front;
    printf("\nDeleted: %d\n", temp->data);

    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
        q->rear = NULL;
}

void peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Empty\n");
        return;
    }

    printf("\nFront Element: %d\n", q->front->data);
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nQueue Empty\n");
        return;
    }

    struct Node *temp = q->front;
    printf("\nQueue Elements:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue q;
    initialize(&q);

    int choice, value;

    while (1) {
        printf("\n===== LINKED QUEUE MENU =====\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
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
        }
    }
}
