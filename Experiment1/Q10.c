#include <stdio.h>
#include <stdlib.h>

// Structure for Student
struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function to input student details
void inputStudents(struct Student *s, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
}

// Function to display student details
void displayStudents(struct Student *s, int n) {
    printf("\n===== Student Records =====\n");
    printf("Roll\tName\tMarks\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

// Function to sort students by marks (Descending order)
void sortStudents(struct Student *s, int n) {
    struct Student temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) {
                // Swap
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    struct Student *students;
    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input
    inputStudents(students, n);

    // Display before sorting
    printf("\n--- Before Sorting ---\n");
    displayStudents(students, n);

    // Sorting
    sortStudents(students, n);

    // Display after sorting
    printf("\n--- After Sorting (Descending by Marks) ---\n");
    displayStudents(students, n);

    // Free memory
    free(students);

    return 0;
}
