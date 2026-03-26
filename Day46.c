#include <stdio.h>
#include <stdlib.h>

/* structure of a binary tree node */
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

    // assign the value to the node
    newNode->data = value;

    // when a node is first created it has no children
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/* queue structure to help with level order traversal */
struct Node* queue[100];  // simple array based queue
int front = 0;
int rear = 0;


/* function to insert element into queue */
void enqueue(struct Node* node)
{
    // place the node at the rear of the queue
    queue[rear] = node;

    // move rear forward
    rear++;
}


/* function to remove element from queue */
struct Node* dequeue()
{
    // take the node from the front of the queue
    struct Node* temp = queue[front];

    // move front forward
    front++;

    return temp;
}


/* function to perform level order traversal */
void levelOrderTraversal(struct Node* root)
{
    // if the tree is empty nothing should be printed
    if(root == NULL)
    {
        return;
    }

    // first put the root node into the queue
    enqueue(root);

    // continue traversal until queue becomes empty
    while(front < rear)
    {
        // remove the current node from queue
        struct Node* current = dequeue();

        // print the value of the node
        printf("%d ", current->data);

        // if left child exists add it to queue
        if(current->left != NULL)
        {
            enqueue(current->left);
        }

        // if right child exists add it to queue
        if(current->right != NULL)
        {
            enqueue(current->right);
        }
    }
}


int main()
{
    /* creating a sample binary tree manually */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    /* calling the level order traversal function */

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
