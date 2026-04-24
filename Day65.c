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

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

// DFS function to detect cycle
int DFS(struct Graph* graph, int v, int visited[], int parent) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];

    while (temp) {
        int adj = temp->vertex;

        // If not visited, recurse
        if (!visited[adj]) {
            if (DFS(graph, adj, visited, v))
                return 1;
        }
        // If visited and not parent → cycle
        else if (adj != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

// Function to check cycle in graph
int hasCycle(struct Graph* graph) {
    int visited[graph->V];

    // Initialize visited array
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Handle disconnected graph
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (DFS(graph, i, visited, -1))
                return 1;
        }
    }

    return 0;
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

    // Check cycle
    if (hasCycle(graph))
        printf("YES");
    else
        printf("NO");

    return 0;
}
