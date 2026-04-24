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

    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    // Initialize all lists as empty
    for (int i = 0; i < V; i++) {
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

// DFS function (recursive)
void DFS(struct Graph* graph, int v, int visited[]) {
    // Mark current node as visited
    visited[v] = 1;

    // Print the node
    printf("%d ", v);

    // Traverse all adjacent vertices
    struct Node* temp = graph->adjList[v];
    while (temp) {
        int adjVertex = temp->vertex;

        // Visit only unvisited nodes
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n); // number of vertices
    scanf("%d", &m); // number of edges

    struct Graph* graph = createGraph(n);

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int start;
    scanf("%d", &start); // starting vertex

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    DFS(graph, start, visited);

    return 0;
}
