#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int roll;
    char name[50];
    float marks;
    struct Student* next;
};
struct Student* createNode(int roll, char name[], float marks) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->next = NULL;
    return newNode;
}
void insertStudent(struct Student** head, int roll, char name[], float marks) {
    struct Student* newNode = createNode(roll, name, marks);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Student* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteStudent(struct Student** head, int roll) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Student* temp = *head;
    struct Student* prev = NULL;
    if (temp->roll == roll) {
        *head = temp->next;
        free(temp);
        printf("Record deleted\n");
        return;
    }
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Record not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Record deleted\n");
}
void searchStudent(struct Student* head, int roll) {
    struct Student* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Record found:\n");
            printf("Roll: %d\nName: %s\nMarks: %.2f\n", temp->roll, temp->name, temp->marks);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found\n");
}
void displayStudents(struct Student* head) {
    if (head == NULL) {
        printf("No records to display\n");
        return;
    }
    struct Student* temp = head;
    while (temp != NULL) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", temp->roll, temp->name, temp->marks);
        temp = temp->next;
    }
}
int main() {
    struct Student* head = NULL;
    int choice, roll;
    char name[50];
    float marks;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter roll, name, marks: ");
                scanf("%d %s %f", &roll, name, &marks);
                insertStudent(&head, roll, name, marks);
                break;
            case 2:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                deleteStudent(&head, roll);
                break;
            case 3:
                printf("Enter roll to search: ");
                scanf("%d", &roll);
                searchStudent(head, roll);
                break;
            case 4:
                displayStudents(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
