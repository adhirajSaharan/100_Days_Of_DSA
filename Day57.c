#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int val) {
    if (val == -1) return NULL;   // -1 means NULL node

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    // Left child → 2*i + 1
    root->left = buildTree(arr, n, 2*i + 1);

    // Right child → 2*i + 2
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Function to convert tree into mirror
void mirrorTree(struct Node* root) {
    if (root == NULL)
        return;

    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively apply to subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);
}

// Inorder traversal (Left → Root → Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read level-order input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build original tree
    struct Node* root = buildTree(arr, n, 0);

    // Convert to mirror
    mirrorTree(root);

    // Print inorder of mirrored tree
    inorder(root);

    return 0;
}
