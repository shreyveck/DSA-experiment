#include <stdio.h>
#define SIZE 100

int heap[SIZE];
int n = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void insert(int val) {
    heap[n] = val;
    heapifyUp(n);
    n++;
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void deleteRoot() {
    if (n == 0) return;

    heap[0] = heap[n-1];
    n--;
    heapifyDown(0);
}

void display() {
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Insert 2.DeleteRoot 3.Display 4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: scanf("%d", &val); insert(val); break;
            case 2: deleteRoot(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}
