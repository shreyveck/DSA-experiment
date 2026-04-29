#include <stdio.h>
#define N 100

int s[N];
int top = -1;

void push(int v) {
    if (top == N - 1) {
        printf("Overflow\n");
    } else {
        s[++top] = v;
    }
}

void pop() {
    if (top == -1) {
        printf("Underflow\n");
    } else {
        printf("Popped: %d\n", s[top--]);
    }
}

void display() {
    if (top == -1) {
        printf("Empty stack\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch, val;

    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
        }
    }
}
