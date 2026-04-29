#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}
void insertBeginning(struct Node** head, int value) {
    insertEnd(head, value);
    *head = (*head)->prev;
}
void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* last = (*head)->prev;
    struct Node* temp = *head;
    *head = temp->next;
    (*head)->prev = last;
    last->next = *head;
    free(temp);
}
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* last = (*head)->prev;
    struct Node* newLast = last->prev;
    newLast->next = *head;
    (*head)->prev = newLast;

    free(last);
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    int count = 0;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("(back to head)\n");
    printf("Total nodes: %d\n", count);
}
int main() {
    struct Node* head = NULL;
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    printf("\nInitial list:\n");
    display(head);
    printf("\nInsert at beginning (enter value): ");
    scanf("%d", &value);
    insertBeginning(&head, value);
    display(head);
    printf("\nInsert at end (enter value): ");
    scanf("%d", &value);
    insertEnd(&head, value);
    display(head);
    deleteBeginning(&head);
    printf("\nAfter deleting from beginning:\n");
    display(head);
    deleteEnd(&head);
    printf("\nAfter deleting from end:\n");
    display(head);
    return 0;
}
