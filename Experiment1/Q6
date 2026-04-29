#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i, maxIndex = 0;
    struct Employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    emp = (struct Employee*)malloc(n * sizeof(struct Employee));

    for(i = 0; i < n; i++) {
        printf("Enter ID, Name, Salary: ");
        scanf("%d %s %f", &emp[i].id, emp[i].name, &emp[i].salary);

        if(emp[i].salary > emp[maxIndex].salary)
            maxIndex = i;
    }

    printf("\nHighest Salary Employee:\n");
    printf("%d %s %.2f\n", emp[maxIndex].id, emp[maxIndex].name, emp[maxIndex].salary);

    free(emp);
    return 0;
}
