#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // Initialize matrix with large value (means no direct edge)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges (undirected graph)
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[n+1];      // minimum weight to connect each node
    int visited[n+1];  // to track included nodes in MST

    // Initialize arrays
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    // Repeat n times (add n nodes to MST)
    for (int count = 1; count <= n; count++) {

        int min = INT_MAX, u = -1;

        // Pick node with minimum key value (not visited)
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;         // include node in MST
        totalWeight += key[u];  // add its edge weight

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", totalWeight);

    return 0;
}
