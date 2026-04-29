#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

char stack[SIZE];
int top = -1;

void push(char ch);
char pop();
int isFull();
int isEmpty();
void displayStack();
void reverseString(char str[]);

int isFull() {
    return (top == SIZE - 1);
}

int isEmpty() {
    return (top == -1);
}

void push(char ch) {
    if (isFull()) {
        printf("Stack Overflow - Cannot insert '%c'\n", ch);
        return;
    }
    top++;
    stack[top] = ch;
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top--];
}

void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents (Top to Bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

void reverseString(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        push(str[i]);
        i++;
    }

    displayStack();

    i = 0;
    while (!isEmpty()) {
        str[i] = pop();
        i++;
    }
}

int main() {
    char str[SIZE];

    printf("----- STRING REVERSAL USING STACK -----\n");

    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("Original String: %s\n", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);

    return 0;
}
