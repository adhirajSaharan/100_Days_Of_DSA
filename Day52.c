#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int val) {
    if (val == -1)   // -1 means NULL
        return NULL;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build tree from level order input
struct Node* buildTree(int arr[], int n, int i) {
    // If index is out of bounds or value is -1 → NULL node
    if (i >= n || arr[i] == -1)
        return NULL;

    // Create current node
    struct Node* root = createNode(arr[i]);

    // Recursively build left and right subtree
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}

// Function to find LCA in Binary Tree
struct Node* findLCA(struct Node* root, int n1, int n2) {

    // Base case
    if (root == NULL)
        return NULL;

    // If current node matches one of the values
    if (root->data == n1 || root->data == n2)
        return root;

    // Search in left and right subtree
    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    // If both sides return non-NULL, current node is LCA
    if (leftLCA && rightLCA)
        return root;

    // Otherwise return non-NULL child
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n;

    // Read number of nodes
    scanf("%d", &n);

    int arr[n];

    // Read level order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree
    struct Node* root = buildTree(arr, n, 0);

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    // Find LCA
    struct Node* lca = findLCA(root, n1, n2);

    // Print result
    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
