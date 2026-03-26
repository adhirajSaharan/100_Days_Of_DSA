#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure for tree node */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;   // store value
    newNode->left = NULL;    // initially no children
    newNode->right = NULL;

    return newNode;
}


/* Function to construct binary tree from level order */
struct Node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;

    /* array to store node pointers */
    struct Node* nodes[MAX];

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;           // NULL node
        else
            nodes[i] = createNode(arr[i]);
    }

    /* link children according to level order */
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


/* Inorder Traversal: Left -> Root -> Right */
void inorder(struct Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


/* Main Function */
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

    /* build tree */
    struct Node* root = buildTree(arr, n);

    /* print inorder traversal */
    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}
