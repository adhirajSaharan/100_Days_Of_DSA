#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Function to find LCA in BST
struct Node* findLCA(struct Node* root, int n1, int n2) {

    while (root != NULL) {

        // If both values are smaller, go left
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // If both values are larger, go right
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // Otherwise this node is LCA
        else
            return root;
    }

    return NULL;
}

int main() {

    int N, x;
    struct Node* root = NULL;

    // Read number of nodes
    scanf("%d", &N);

    // Read node values and build BST
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    // Print LCA value
    if (lca != NULL)
        printf("%d", lca->data);

    return 0;
}
