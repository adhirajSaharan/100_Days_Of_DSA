#include <stdio.h>
#include <stdlib.h>

/* structure for BST node */
struct Node
{
    int data;              // value stored in node
    struct Node* left;     // pointer to left child
    struct Node* right;    // pointer to right child
};

/* function to create a new node */
struct Node* createNode(int value)
{
    // allocate memory for node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // assign value
    newNode->data = value;

    // initialize children to NULL
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/* function to insert node in BST */
struct Node* insert(struct Node* root, int value)
{
    // if tree is empty create node
    if(root == NULL)
    {
        return createNode(value);
    }

    // if value smaller go left
    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }

    // if value greater go right
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}


/* function to search an element in BST */
int search(struct Node* root, int key)
{
    // if tree empty or element found
    if(root == NULL)
    {
        return 0;   // element not found
    }

    if(root->data == key)
    {
        return 1;   // element found
    }

    // if key smaller search left subtree
    if(key < root->data)
    {
        return search(root->left, key);
    }

    // if key greater search right subtree
    else
    {
        return search(root->right, key);
    }
}


int main()
{
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    if(search(root, key))
    {
        printf("Element Found\n");
    }
    else
    {
        printf("Element Not Found\n");
    }

    return 0;
}
