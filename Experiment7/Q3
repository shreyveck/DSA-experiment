#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], n;

void inputGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
}

void display() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

void degree(int v) {
    int in = 0, out = 0;

    for (int i = 0; i < n; i++) {
        if (adj[i][v]) in++;
        if (adj[v][i]) out++;
    }

    printf("In-degree: %d\nOut-degree: %d\n", in, out);
}

int main() {
    int v;
    inputGraph();
    display();

    printf("Enter vertex: ");
    scanf("%d", &v);

    degree(v);
    return 0;
}
