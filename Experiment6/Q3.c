#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Node {
    int data;
    int priority;
};

struct PriorityQueue {
    struct Node heap[SIZE];
    int size;
};

void initialize(struct PriorityQueue *pq) {
    pq->size = 0;
}

int isEmpty(struct PriorityQueue *pq) {
    return pq->size == 0;
}

int isFull(struct PriorityQueue *pq) {
    return pq->size == SIZE;
}

void swap(struct Node *a, struct Node *b) {
    struct Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && pq->heap[parent].priority > pq->heap[index].priority) {
        printf("[HEAPIFY-UP] Swapping (%d,%d) with (%d,%d)\n",
               pq->heap[parent].data, pq->heap[parent].priority,
               pq->heap[index].data, pq->heap[index].priority);

        swap(&pq->heap[parent], &pq->heap[index]);

        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(struct PriorityQueue *pq, int data, int priority) {
    if (isFull(pq)) {
        printf("\n[ERROR] Priority Queue Overflow!\n");
        return;
    }

    printf("\n[INFO] Inserting element %d with priority %d\n", data, priority);

    pq->heap[pq->size].data = data;
    pq->heap[pq->size].priority = priority;

    heapifyUp(pq, pq->size);

    pq->size++;
}

void heapifyDown(struct PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->heap[left].priority < pq->heap[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->heap[right].priority < pq->heap[smallest].priority)
        smallest = right;

    if (smallest != index) {
        printf("[HEAPIFY-DOWN] Swapping (%d,%d) with (%d,%d)\n",
               pq->heap[index].data, pq->heap[index].priority,
               pq->heap[smallest].data, pq->heap[smallest].priority);

        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

void deletePQ(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("\n[ERROR] Priority Queue Underflow!\n");
        return;
    }

    printf("\n[INFO] Removing element with highest priority: (%d,%d)\n",
           pq->heap[0].data, pq->heap[0].priority);

    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    heapifyDown(pq, 0);
}

void peek(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("\n[INFO] Priority Queue is Empty\n");
        return;
    }

    printf("\n[INFO] Highest Priority Element: (%d,%d)\n",
           pq->heap[0].data, pq->heap[0].priority);
}

void display(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("\n[INFO] Priority Queue is Empty\n");
        return;
    }

    printf("\n===== PRIORITY QUEUE ELEMENTS =====\n");
    printf("(Data , Priority)\n");

    for (int i = 0; i < pq->size; i++) {
        printf("(%d , %d)\n", pq->heap[i].data, pq->heap[i].priority);
    }
}

int main() {
    struct PriorityQueue pq;
    initialize(&pq);

    int choice, data, priority;

    while (1) {
        printf("\n========== PRIORITY QUEUE MENU ==========\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue Highest Priority)\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (smaller = higher priority): ");
                scanf("%d", &priority);
                insert(&pq, data, priority);
                break;

            case 2:
                deletePQ(&pq);
                break;

            case 3:
                peek(&pq);
                break;

            case 4:
                display(&pq);
                break;

            case 5:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\n[WARNING] Invalid choice! Try again.\n");
        }
    }

    return 0;
}
