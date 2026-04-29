#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 200

char stack[SIZE];
int top = -1;

void push(char ch);
char pop();
int isEmpty();
int isFull();
int isMatchingPair(char open, char close);
int checkBalanced(char exp[]);

int isFull() {
    return (top == SIZE - 1);
}

int isEmpty() {
    return (top == -1);
}

void push(char ch) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int checkBalanced(char exp[]) {
    int i;
    char ch;

    for (i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {

            if (isEmpty()) {
                return 0;   // Unbalanced
            }

            ch = pop();

            if (!isMatchingPair(ch, exp[i])) {
                return 0;   // Mismatch
            }
        }
    }

    return isEmpty();
}

int main() {
    char exp[SIZE];

    printf("----- CHECK BALANCED EXPRESSION -----\n");
    printf("Enter expression: ");

    fgets(exp, SIZE, stdin);

    if (checkBalanced(exp)) {
        printf("Expression is Balanced\n");
    } else {
        printf("Expression is NOT Balanced\n");
    }

    return 0;
}
