#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adjList;
};

// Create node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

// Add edge (DIRECTED, weighted)
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;
}

// Structure for priority queue node
struct PQNode {
    int vertex;
    int dist;
};

// Min heap (simple version)
struct PQNode pq[MAX];
int size = 0;

// Swap
void swap(struct PQNode* a, struct PQNode* b) {
    struct PQNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i > 0 && pq[(i - 1) / 2].dist > pq[i].dist) {
        swap(&pq[i], &pq[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && pq[left].dist < pq[smallest].dist)
        smallest = left;

    if (right < size && pq[right].dist < pq[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&pq[i], &pq[smallest]);
        heapifyDown(smallest);
    }
}

// Push into PQ
void push(int v, int d) {
    pq[size].vertex = v;
    pq[size].dist = d;
    heapifyUp(size);
    size++;
}

// Pop min
struct PQNode pop() {
    struct PQNode top = pq[0];
    pq[0] = pq[size - 1];
    size--;
    heapifyDown(0);
    return top;
}

// Check empty
int isEmpty() {
    return size == 0;
}

// Dijkstra Algorithm
void dijkstra(struct Graph* graph, int src) {
    int dist[graph->V];

    // Initialize distances
    for (int i = 0; i < graph->V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    push(src, 0);

    while (!isEmpty()) {
        struct PQNode curr = pop();
        int u = curr.vertex;

        struct Node* temp = graph->adjList[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < graph->V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d", &n); // vertices
    scanf("%d", &m); // edges

    struct Graph* graph = createGraph(n);

    int u, v, w;

    // Input edges: u v weight
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
