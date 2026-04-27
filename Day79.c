#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Node for adjacency list
struct Node {
    int v, w;
    struct Node* next;
};

// Create node
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->v = v;
    temp->w = w;
    temp->next = NULL;
    return temp;
}

// Graph
struct Node* adj[MAX];

// Add edge (undirected)
void addEdge(int u, int v, int w) {
    struct Node* temp = newNode(v, w);
    temp->next = adj[u];
    adj[u] = temp;

    temp = newNode(u, w);
    temp->next = adj[v];
    adj[v] = temp;
}

// Min heap structure
struct Pair {
    int v, dist;
};

struct Pair heap[MAX];
int size = 0;

// Swap
void swap(struct Pair* a, struct Pair* b) {
    struct Pair t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void up(int i) {
    while (i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void down(int i) {
    int l = 2*i+1, r = 2*i+2, smallest = i;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        down(smallest);
    }
}

// Push
void push(int v, int d) {
    heap[size].v = v;
    heap[size].dist = d;
    up(size);
    size++;
}

// Pop
struct Pair pop() {
    struct Pair top = heap[0];
    heap[0] = heap[size-1];
    size--;
    down(0);
    return top;
}

// Dijkstra
void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        struct Pair cur = pop();
        int u = cur.v;

        struct Node* temp = adj[u];

        while (temp) {
            int v = temp->v;
            int w = temp->w;

            // Relaxation
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    int u, v, w;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}
