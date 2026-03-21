#include <stdio.h>

#define MAX 100   // Maximum size of circular queue

int queue[MAX];
int front = -1;
int rear = -1;

/* Function to insert element into circular queue */
void enqueue(int value) {

    // Check queue overflow
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    // First element insertion
    if (front == -1) {
        front = rear = 0;
    } 
    else {
        rear = (rear + 1) % MAX;   // Move rear circularly
    }

    queue[rear] = value;
}

/* Function to remove element from circular queue */
void dequeue() {

    // Check queue underflow
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    // If only one element present
    if (front == rear) {
        front = rear = -1;
    } 
    else {
        front = (front + 1) % MAX;  // Move front circularly
    }
}

/* Function to display elements from front to rear */
void display() {

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;  // Circular traversal
    }
}

int main() {
    int n, m, value;

    // Number of elements to enqueue
    scanf("%d", &n);

    // Insert elements into queue
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Number of dequeue operations
    scanf("%d", &m);

    // Perform dequeue operations
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display remaining queue elements
    display();

    return 0;
}
