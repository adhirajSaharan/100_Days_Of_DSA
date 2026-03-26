#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Structure for a binary tree node */
struct Node
{
    int data;               // value stored in node
    struct Node* left;      // pointer to left child
    struct Node* right;     // pointer to right child
};

/* Function to create a new node */
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;   // store data
    newNode->left = NULL;    // initially no children
    newNode->right = NULL;

    return newNode;
}


/* Function to build tree from level order array */
struct Node* buildTree(int arr[], int n)
{
    struct Node* nodes[MAX];

    /* create node objects for each element */
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;           // -1 means NULL node
        else
            nodes[i] = createNode(arr[i]);
    }

    /* connect children using level-order formula */
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

    return nodes[0];   // first element is root
}


/* ---------- INORDER TRAVERSAL ---------- */
/* Left -> Root -> Right */
void inorder(struct Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


/* ---------- PREORDER TRAVERSAL ---------- */
/* Root -> Left -> Right */
void preorder(struct Node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


/* ---------- POSTORDER TRAVERSAL ---------- */
/* Left -> Right -> Root */
void postorder(struct Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


/* ---------- MAIN FUNCTION ---------- */

int main()
{
    int n;
    int arr[MAX];

    /* read number of nodes */
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    /* read level order traversal */
    printf("Enter level order elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* construct binary tree */
    struct Node* root = buildTree(arr, n);

    /* print traversals */

    /* Inorder */
    inorder(root);
    printf("\n");

    /* Preorder */
    preorder(root);
    printf("\n");

    /* Postorder */
    postorder(root);

    return 0;
}
