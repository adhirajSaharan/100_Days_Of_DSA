#include <stdio.h>

#define MAX 100

/* Queue implementation using array */
int queue[MAX];
int front = -1;
int rear = -1;

/* Stack implementation using array */
int stack[MAX];
int top = -1;


/* ---------- QUEUE FUNCTIONS ---------- */

/* insert element into queue */
void enqueue(int value)
{
    if(rear == MAX - 1)   // check if queue is full
    {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)       // first element insertion
        front = 0;

    rear++;
    queue[rear] = value;
}

/* remove element from queue */
int dequeue()
{
    int value = queue[front];
    front++;              // move front forward
    return value;
}


/* ---------- STACK FUNCTIONS ---------- */

/* push element into stack */
void push(int value)
{
    top++;                // move top up
    stack[top] = value;   // store element
}

/* pop element from stack */
int pop()
{
    int value = stack[top];
    top--;                // move top down
    return value;
}


/* ---------- MAIN PROGRAM ---------- */

int main()
{
    int n, value;

    /* read number of elements */
    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* read queue elements */
    printf("Enter queue elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(value);
    }

    /* Step 1: remove elements from queue and push to stack */
    while(front <= rear)
    {
        push(dequeue());
    }

    /* Step 2: pop elements from stack and enqueue back */
    while(top != -1)
    {
        enqueue(pop());
    }

    /* display reversed queue */
    printf("Reversed Queue:\n");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}
