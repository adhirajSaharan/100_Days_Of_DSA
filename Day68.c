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

// Kahn's Algorithm
void topologicalSort(struct Graph* graph) {

    int indegree[graph->V];

    // Step 1: Initialize indegree array
    for (int i = 0; i < graph->V; i++) {
        indegree[i] = 0;
    }

    // Step 2: Calculate indegree of each node
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Step 3: Queue for nodes with indegree 0
    int queue[1000];
    int front = 0, rear = 0;

    // Add all nodes with indegree 0 to queue
    for (int i = 0; i < graph->V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0; // to check cycle

    // Step 4: Process queue
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        count++;

        // Reduce indegree of neighbors
        struct Node* temp = graph->adjList[current];
        while (temp) {
            indegree[temp->vertex]--;

            // If indegree becomes 0, add to queue
            if (indegree[temp->vertex] == 0) {
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }

    // Step 5: Check for cycle
    if (count != graph->V) {
        printf("\nCycle detected! Topological sort not possible.");
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

    // Perform topological sort
    topologicalSort(graph);

    return 0;
}
