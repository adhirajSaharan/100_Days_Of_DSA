#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Function for zigzag traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    // Queue for level order traversal
    struct Node* queue[200];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;  // direction flag

    while (front < rear) {
        int size = rear - front;

        // Temporary array to store current level
        int level[200];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            // Determine index based on direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = curr->data;

            // Add children to queue
            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        // Print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        // Flip direction
        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read level-order input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree
    struct Node* root = buildTree(arr, n, 0);

    // Print zigzag traversal
    zigzagTraversal(root);

    return 0;
}
