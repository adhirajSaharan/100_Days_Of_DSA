#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

/* insert element at front */
void push_front(int x)
{
    if(front == 0)
        printf("Overflow\n");
    else
    {
        if(front == -1)   // first element
        {
            front = rear = 0;
        }
        else
        {
            front--;
        }
        deque[front] = x;
    }
}

/* insert element at rear */
void push_back(int x)
{
    if(rear == MAX-1)
        printf("Overflow\n");
    else
    {
        if(front == -1)   // first element
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        deque[rear] = x;
    }
}

/* delete from front */
void pop_front()
{
    if(front == -1)
        printf("Underflow\n");
    else
    {
        printf("Deleted: %d\n", deque[front]);
        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
}

/* delete from rear */
void pop_back()
{
    if(front == -1)
        printf("Underflow\n");
    else
    {
        printf("Deleted: %d\n", deque[rear]);
        if(front == rear)
            front = rear = -1;
        else
            rear--;
    }
}

/* show front element */
void show_front()
{
    if(front != -1)
        printf("Front: %d\n", deque[front]);
}

/* show rear element */
void show_back()
{
    if(rear != -1)
        printf("Rear: %d\n", deque[rear]);
}

/* display deque */
void display()
{
    if(front == -1)
        printf("Deque empty\n");
    else
    {
        for(int i = front; i <= rear; i++)
            printf("%d ", deque[i]);
        printf("\n");
    }
}

/* main function */
int main()
{
    push_back(10);
    push_front(5);
    push_back(20);

    display();

    show_front();
    show_back();

    pop_front();
    display();

    pop_back();
    display();

    return 0;
}
