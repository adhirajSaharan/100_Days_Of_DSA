#include <stdio.h>
#include <stdlib.h>

/* structure of a node in the binary tree */
struct Node
{
    int data;              // value stored in the node
    struct Node* left;     // pointer to left child
    struct Node* right;    // pointer to right child
};


/* function to create a new node */
struct Node* createNode(int value)
{
    // allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // store the given value in the node
    newNode->data = value;

    // when node is created it has no children
    newNode->left = NULL;
    newNode->right = NULL;

    // return the created node
    return newNode;
}


/* function to calculate height of the binary tree */
int height(struct Node* root)
{
    // if the tree is empty then height is 0
    if(root == NULL)
    {
        return 0;
    }

    // recursively find height of left subtree
    int leftHeight = height(root->left);

    // recursively find height of right subtree
    int rightHeight = height(root->right);

    // height of current node is max(leftHeight, rightHeight) + 1
    if(leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}


int main()
{
    /* creating a simple binary tree manually */

    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->left->left->left = createNode(6);

    /* calculate height of the tree */
    int h = height(root);

    // print the height
    printf("Height of Binary Tree: %d\n", h);

    return 0;
}
