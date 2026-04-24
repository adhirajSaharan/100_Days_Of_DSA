#include <stdio.h>

int main() {
    int n, m;

    // Input number of vertices and edges
    scanf("%d", &n);
    scanf("%d", &m);

    int adj[n][n];

    // Initialize matrix with 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Add edge (for undirected graph)
        adj[u][v] = 1;
        adj[v][u] = 1;

        // 👉 For directed graph, comment the below line:
        // adj[v][u] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
