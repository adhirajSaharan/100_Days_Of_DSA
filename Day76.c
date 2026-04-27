#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adjList;
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjList = (struct Node**)malloc((V + 1) * sizeof(struct Node*));

    // Initialize adjacency list (1-based indexing)
    for (int i = 1; i <= V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

// DFS function
void DFS(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int visited[n + 1];

    // Initialize visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    int components = 0;

    // Check every vertex
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            components++;  // new component found
        }
    }

    printf("%d", components);

    return 0;
}
