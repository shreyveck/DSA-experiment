#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int tree[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;   // -1 means empty
    }
}

void insert(int value, int index) {
    if (index >= SIZE) {
        printf("\n[ERROR] Index out of range!\n");
        return;
    }

    if (tree[index] != -1) {
        printf("\n[WARNING] Node already exists at index %d\n", index);
        return;
    }

    tree[index] = value;
    printf("\n[INFO] Inserted %d at index %d\n", value, index);
}

void display() {
    printf("\n===== TREE ELEMENTS =====\n");

    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1) {
            printf("Index %d : %d\n", i, tree[i]);
        }
    }
}

int findIndex(int value) {
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] == value)
            return i;
    }
    return -1;
}

void showRelations(int value) {
    int index = findIndex(value);

    if (index == -1) {
        printf("\n[ERROR] Node not found!\n");
        return;
    }

    printf("\nNode: %d (Index %d)\n", value, index);

    if (index == 0) {
        printf("Parent: None (Root Node)\n");
    } else {
        int parentIndex = (index - 1) / 2;
        if (tree[parentIndex] != -1)
            printf("Parent: %d\n", tree[parentIndex]);
        else
            printf("Parent: None\n");
    }

    int leftIndex = 2 * index + 1;
    if (leftIndex < SIZE && tree[leftIndex] != -1)
        printf("Left Child: %d\n", tree[leftIndex]);
    else
        printf("Left Child: None\n");

    int rightIndex = 2 * index + 2;
    if (rightIndex < SIZE && tree[rightIndex] != -1)
        printf("Right Child: %d\n", tree[rightIndex]);
    else
        printf("Right Child: None\n");
}

int main() {
    int choice, value, index;

    initialize();

    while (1) {
        printf("\n===== BINARY TREE MENU =====\n");
        printf("1. Insert Element\n");
        printf("2. Display Tree\n");
        printf("3. Show Parent/Children\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                printf("Enter index (0 for root): ");
                scanf("%d", &index);

                insert(value, index);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter node value: ");
                scanf("%d", &value);

                showRelations(value);
                break;

            case 4:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
