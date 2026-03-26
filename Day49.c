#include <stdio.h>
#include <stdlib.h>

/* structure for a node in BST */
struct Node
{
    int data;               // value stored in the node
    struct Node* left;      // pointer to left child
    struct Node* right;     // pointer to right child
};

/* function to create a new node */
struct Node* createNode(int value)
{
    // allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // store the value
    newNode->data = value;

    // initially left and right children are NULL
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/* function to insert a value into BST */
struct Node* insert(struct Node* root, int value)
{
    // if tree is empty, create new node and return it
    if(root == NULL)
    {
        return createNode(value);
    }

    // if value is smaller than root, go to left subtree
    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }

    // if value is greater than root, go to right subtree
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    // return root after insertion
    return root;
}


/* inorder traversal to display BST */
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        // visit left subtree
        inorder(root->left);

        // print node value
        printf("%d ", root->data);

        // visit right subtree
        inorder(root->right);
    }
}


int main()
{
    struct Node* root = NULL;

    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter values to insert into BST:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder Traversal of BST: ");
    inorder(root);

    return 0;
}
