#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], n;

int main() {
    printf("Enter vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int flag = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j] != adj[j][i])
                flag = 0;

    if (flag)
        printf("Undirected Graph\n");
    else
        printf("Directed Graph\n");

    return 0;
}
