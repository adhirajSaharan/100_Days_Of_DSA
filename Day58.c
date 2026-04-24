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
struct Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {

    // Base case
    if (inStart > inEnd)
        return NULL;

    // Pick current root from preorder
    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = createNode(rootVal);

    // If this node has no children
    if (inStart == inEnd)
        return root;

    // Find root in inorder array
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);

    // Build left and right subtrees
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

// Postorder traversal (Left → Right → Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Read preorder
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    // Read inorder
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    // Build tree
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    // Print postorder traversal
    postorder(root);

    return 0;
}
