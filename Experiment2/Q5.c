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
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverseData(struct Node* head) {
    int n = countNodes(head);
    if (n == 0) return;
    int *arr = (int*)malloc(n * sizeof(int));
    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    temp = head;
    for (int i = n - 1; i >= 0; i--) {
        temp->data = arr[i];
        temp = temp->next;
    }
    free(arr);
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    printf("Original List:\n");
    display(head);
    reverseData(head);
    printf("After Reversing Data:\n");
    display(head);
    return 0;
}
