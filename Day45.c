#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure for a binary tree node */
struct Node
{
    int data;               // value stored in the node
    struct Node* left;      // pointer to left child
    struct Node* right;     // pointer to right child
};

/* Function to create a new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;   // initially no children
    newNode->right = NULL;

    return newNode;
}


/* Function to build binary tree from level order array */
struct Node* buildTree(int arr[], int n)
{
    struct Node* nodes[MAX];

    /* Create node objects */
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;          // -1 means no node
        else
            nodes[i] = createNode(arr[i]);
    }

    /* Link children based on level-order rule */
    for(int i = 0; i < n; i++)
    {
        if(nodes[i] != NULL)
        {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if(rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    return nodes[0];   // root node
}


/* Function to find height of binary tree */
int height(struct Node* root)
{
    if(root == NULL)
        return 0;    // empty tree height = 0

    /* find height of left subtree */
    int leftHeight = height(root->left);

    /* find height of right subtree */
    int rightHeight = height(root->right);

    /* height = max(leftHeight, rightHeight) + 1 */
    if(leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}


/* Main function */
int main()
{
    int n;
    int arr[MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter level order elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* build the tree */
    struct Node* root = buildTree(arr, n);

    /* calculate height */
    int h = height(root);

    printf("%d", h);

    return 0;
}
