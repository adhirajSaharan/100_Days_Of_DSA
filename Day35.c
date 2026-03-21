#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum size of queue

int queue[MAX];
int front = -1;
int rear = -1;

/* Function to insert element into queue (enqueue) */
void enqueue(int value) {

    // Check queue overflow
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    // If first element is inserted
    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
}

/* Function to display queue elements from front to rear */
void display() {

    if (front == -1) {  // Queue empty
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, value;

    // Read number of elements
    scanf("%d", &n);

    // Insert n elements into queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Display queue elements
    display();

    return 0;
}
