#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* stack[100];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void inorder(struct Node* root) {
    struct Node* curr = root;

    while (curr != NULL || !isEmpty()) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

void preorder(struct Node* root) {
    if (root == NULL) return;

    push(root);

    while (!isEmpty()) {
        struct Node* temp = pop();
        printf("%d ", temp->data);

        if (temp->right)
            push(temp->right);
        if (temp->left)
            push(temp->left);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    return 0;
}
