#include <stdio.h>

#define MAX 100   // Maximum size of the stack

int stack[MAX];
int top = -1;     // Top pointer of stack

// Function to push an element into stack
void push(int value) {
    if (top == MAX - 1) {           // Check stack overflow
        printf("Stack Overflow\n");
    } else {
        top++;                      // Move top up
        stack[top] = value;         // Insert value
    }
}

// Function to pop an element from stack
void pop() {
    if (top == -1) {                // Check stack underflow
        printf("Stack Underflow\n");
    } else {
        top--;                      // Remove top element
    }
}

int main() {
    int n, m, i, value;

    // Read number of elements to push
    scanf("%d", &n);

    // Read and push n elements into stack
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Read number of pop operations
    scanf("%d", &m);

    // Perform pop operations
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining elements from top to bottom
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}
