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

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Add edge (DIRECTED)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
}

// DFS helper for topological sort
void topoDFS(struct Graph* graph, int v, int visited[], int stack[], int* top) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp) {
        int adj = temp->vertex;

        if (!visited[adj]) {
            topoDFS(graph, adj, visited, stack, top);
        }

        temp = temp->next;
    }

    // Push current node to stack AFTER visiting neighbors
    stack[++(*top)] = v;
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    int visited[graph->V];
    int stack[graph->V];
    int top = -1;

    // Initialize visited
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Call DFS for all unvisited nodes
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topoDFS(graph, i, visited, stack, &top);
        }
    }

    // Print stack in reverse (top → bottom)
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n); // vertices
    scanf("%d", &m); // edges

    struct Graph* graph = createGraph(n);

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    // Print topological order
    topologicalSort(graph);

    return 0;
}
