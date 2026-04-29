#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    top = top + 1;
    stack[top] = x;
}

int pop() {
    int val;
    val = stack[top];
    top = top - 1;
    return val;
}

int main() {
    char exp[] = "23*54*+9-";
    int i;
    int a, b, result;

    for (i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else {
            b = pop();
            a = pop();

            if (exp[i] == '+')
                push(a + b);
            else if (exp[i] == '-')
                push(a - b);
            else if (exp[i] == '*')
                push(a * b);
            else if (exp[i] == '/')
                push(a / b);
        }
    }

    result = pop();

    printf("Result = %d\n", result);

    return 0;
}
