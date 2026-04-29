#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
int count_nodes(struct node *head) {
    int total = 0;
    struct node *current = head;
    while (current != NULL) {
        total++;
        current = current->next;
    }
    return total;
}

int main() {
    struct node *head = NULL, *tail = NULL, *newnode;
    int n, value, i;
    printf("Enter how many nodes you want: ");
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
    printf("Total nodes in the list = %d\n", count_nodes(head));
    return 0;
}

