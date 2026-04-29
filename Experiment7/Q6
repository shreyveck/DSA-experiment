#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int start;

    printf("Enter vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter start vertex: ");
    scanf("%d", &start);

    dfs(start);

    return 0;
}
