#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}
void insertTerm(struct Node** head, int c, int e) {
    struct Node* newNode = createNode(c, e);
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
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
double evaluatePolynomial(struct Node* head, int x) {
    double result = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}
int main() {
    struct Node* poly = NULL;
    int n, c, e, x;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        insertTerm(&poly, c, e);
    }
    printf("\nPolynomial: ");
    displayPolynomial(poly);
    printf("Enter value of x: ");
    scanf("%d", &x);
    double value = evaluatePolynomial(poly, x);
    printf("Polynomial value at x = %d is %.2lf\n", x, value);
    return 0;
}
