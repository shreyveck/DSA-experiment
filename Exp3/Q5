#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}

int main() {
    char exp[] = "A+B*(C^D-E)^(F+G*H)-I";
    char result[MAX];
    int i, k = 0;
    char ch;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (isalnum(ch)) {
            result[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(') {
                result[k++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                result[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        result[k++] = pop();
    }

    result[k] = '\0';

    printf("Postfix Expression: %s\n", result);

    return 0;
}
