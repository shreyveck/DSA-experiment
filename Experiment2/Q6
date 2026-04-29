#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void createList(struct Node** head, int n) {
    int value;
    struct Node *temp, *last;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (*head == NULL) {
            *head = temp;
            temp->next = *head;
            last = temp;
        } else {
            temp->next = *head;
            last->next = temp;
            last = temp;
        }
    }
}
void insertBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
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
    struct Node* temp = *head;
    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    *head = temp->next;
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
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = *head;
    free(temp);
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    int count = 0;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    } while (temp != head);
    printf("(back to head)\n");
    printf("Total nodes: %d\n", count);
}
int main() {
    struct Node* head = NULL;
    int n, choice, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    createList(&head, n);
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
