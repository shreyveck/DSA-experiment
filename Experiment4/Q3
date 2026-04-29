#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

struct Queue {
    char arr[SIZE];
    int front, rear;
};

void init(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue *q, char ch) {
    q->arr[++q->rear] = ch;
}

char dequeue(struct Queue *q) {
    return q->arr[q->front++];
}

int main() {
    struct Queue q;
    init(&q);

    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        enqueue(&q, tolower(str[i]));
    }

    int flag = 1;

    for (int i = len - 1; i >= 0; i--) {
        if (tolower(str[i]) != dequeue(&q)) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
