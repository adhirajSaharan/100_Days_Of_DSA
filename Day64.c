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

    // Initialize adjacency list
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

// BFS function
void BFS(struct Graph* graph, int start) {
    int visited[graph->V];

    // Initialize visited array
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    // Queue for BFS
    int queue[1000];
    int front = 0, rear = 0;

    // Start from source
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        // Print current node
        printf("%d ", current);

        // Traverse all neighbors
        struct Node* temp = graph->adjList[current];
        while (temp) {
            int adjVertex = temp->vertex;

            // If not visited, mark and enqueue
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
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

    int start;
    scanf("%d", &start); // source vertex

    // Perform BFS
    BFS(graph, start);

    return 0;
}
