#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int search_element(struct node *head, int key) {
    int position = 1;
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}
int main() {
    struct node *head = NULL, *tail = NULL, *newnode;
    int n, value, key, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    int result = search_element(head, key);
    if (result == -1) {
        printf("Element does not exist in the list\n");
    } else {
        printf("Element found at position %d\n", result);
    }
    return 0;
}
