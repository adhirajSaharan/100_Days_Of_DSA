#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue implementation using array
struct Node* queue[1000];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(struct Node* node) {
    if (rear == 999) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

// Dequeue operation
struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to build tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (!isEmpty() && i < n) {
        struct Node* current = dequeue();

        // Left child
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

// Function to print right view
void rightView(struct Node* root) {
    if (root == NULL) return;

    // Reset queue
    front = rear = -1;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front + 1;

        // Traverse one level
        for (int i = 0; i < levelSize; i++) {
            struct Node* temp = dequeue();

            // Print last node of this level
            if (i == levelSize - 1) {
                printf("%d ", temp->data);
            }

            // Add children
            if (temp->left) enqueue(temp->left);
            if (temp->right) enqueue(temp->right);
        }
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}
