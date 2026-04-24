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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Find index of value in inorder array
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build tree
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {

    // Base case
    if (inStart > inEnd)
        return NULL;

    // Last element of postorder is root
    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    // If only one node
    if (inStart == inEnd)
        return root;

    // Find root in inorder array
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // IMPORTANT:
    // Build RIGHT subtree first (because we are going backwards in postorder)
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal (Root → Left → Right)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    // Read inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    // Read postorder
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    // Build tree
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    // Print preorder traversal
    preorder(root);

    return 0;
}
