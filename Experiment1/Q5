#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    struct Student *s;

    s = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Roll No, Name, Marks:\n");
    scanf("%d %s %f", &s->roll, s->name, &s->marks);

    printf("\nStudent Details:\n");
    printf("Roll: %d\nName: %s\nMarks: %.2f\n", s->roll, s->name, s->marks);

    free(s);
    return 0;
}
