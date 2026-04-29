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

struct Node* insert(struct Node* root) {
    int val;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    root = createNode(val);

    printf("Enter left child of %d\n", val);
    root->left = insert(root->left);

    printf("Enter right child of %d\n", val);
    root->right = insert(root->right);

    return root;
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    struct Node* root = NULL;

    printf("Create Binary Tree\n");
    root = insert(root);

    printf("\nTotal Nodes: %d\n", countNodes(root));
    printf("Leaf Nodes: %d\n", countLeaf(root));
    printf("Height: %d\n", height(root));

    return 0;
}
