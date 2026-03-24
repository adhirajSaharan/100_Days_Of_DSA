#include <stdio.h>
#include <stdlib.h>

/* 
   Node structure for the linked list.
   Each node stores one value of the queue
   and a pointer to the next node.
*/
struct Node
{
    int data;
    struct Node* next;
};

/* 
   In a queue we maintain two pointers:
   front -> first element of the queue
   rear  -> last element of the queue
*/
struct Node* front = NULL;
struct Node* rear = NULL;


/* enqueue operation inserts element at the rear of the queue */
void enqueue(int value)
{
    /* create a new node dynamically */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;   // store the value in node
    newNode->next = NULL;    // since it will be the last node

    /* if queue is empty, both front and rear should point to this node */
    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        /* attach new node after the current rear */
        rear->next = newNode;

        /* move rear pointer to the new node */
        rear = newNode;
    }
}


/* dequeue operation removes element from the front of queue */
int dequeue()
{
    /* if queue is empty nothing can be removed */
    if(front == NULL)
    {
        return -1;
    }

    /* store the node currently at front */
    struct Node* temp = front;

    int value = temp->data;   // value to return

    /* move front pointer to next node */
    front = front->next;

    /* if queue becomes empty after deletion */
    if(front == NULL)
    {
        rear = NULL;
    }

    /* free memory of removed node */
    free(temp);

    return value;
}


int main()
{
    int N;
    scanf("%d", &N);   // number of operations

    char operation[20];

    while(N--)
    {
        scanf("%s", operation);

        /* check if operation is enqueue */
        if(operation[0] == 'e')   // enqueue
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }

        /* check if operation is dequeue */
        else if(operation[0] == 'd')
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}
