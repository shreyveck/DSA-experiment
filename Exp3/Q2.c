#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void pushElement(int val);
void popElement();
void displayStack();
int isEmpty();

int main() {
    int choice, value;

    while (1) {
        printf("\n----- STACK USING LINKED LIST -----\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                pushElement(value);
                break;

            case 2:
                popElement();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

int isEmpty() {
    if (top == NULL)
        return 1;
    else
        return 0;
}

void pushElement(int val) {
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL) {
        printf("Memory allocation failed (Overflow)\n");
        return;
    }

    newNode->data = val;
    newNode->next = top;
    top = newNode;

    printf("Element %d inserted successfully\n", val);
}

void popElement() {
    struct node *temp;

    if (isEmpty()) {
        printf("Stack Underflow (Nothing to delete)\n");
        return;
    }

    temp = top;
    printf("Deleted element: %d\n", temp->data);

    top = top->next;
    free(temp);
}

void displayStack() {
    struct node *temp;

    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements (Top to Bottom):\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
