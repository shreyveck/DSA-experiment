#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c, i, j;
    int **a, **b, **sum, **diff;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    a = (int**)malloc(r * sizeof(int*));
    b = (int**)malloc(r * sizeof(int*));
    sum = (int**)malloc(r * sizeof(int*));
    diff = (int**)malloc(r * sizeof(int*));

    for(i = 0; i < r; i++) {
        a[i] = (int*)malloc(c * sizeof(int));
        b[i] = (int*)malloc(c * sizeof(int));
        sum[i] = (int*)malloc(c * sizeof(int));
        diff[i] = (int*)malloc(c * sizeof(int));
    }

    printf("Enter Matrix A:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("Enter Matrix B:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            diff[i][j] = a[i][j] - b[i][j];
        }

    printf("\nAddition:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
            printf("%d ", sum[i][j]);
        printf("\n");
    }

    printf("\nSubtraction:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++)
            printf("%d ", diff[i][j]);
        printf("\n");
    }

    return 0;
}
