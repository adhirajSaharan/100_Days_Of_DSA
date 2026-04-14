#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for queue (used in BFS)
struct QNode {
    struct Node* node;
    int hd;   // horizontal distance
};

// Create new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree using level order (array representation)
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Function for vertical order traversal
void verticalOrder(struct Node* root) {

    // Array to store nodes for each horizontal distance
    int map[200][200];   // simple 2D storage
    int count[200] = {0};

    int offset = 100;  // to handle negative indices

    // Queue for BFS
    struct QNode queue[200];
    int front = 0, rear = 0;

    // Push root with hd = 0
    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        if (curr == NULL) continue;

        // Store node value
        map[hd + offset][count[hd + offset]++] = curr->data;

        // Push left and right children
        queue[rear++] = (struct QNode){curr->left, hd - 1};
        queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print vertical order from leftmost to rightmost
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read level order input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree
    struct Node* root = buildTree(arr, n, 0);

    // Print vertical order
    verticalOrder(root);

    return 0;
}
