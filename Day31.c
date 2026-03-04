#include <stdio.h>

#define MAX 100  // Maximum size of stack

int stack[MAX];
int top = -1;  // Stack is initially empty

// Function to push element into stack
void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = value;
}

// Function to pop element from stack
void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("%d\n", stack[top]);
    top--;
}

// Function to display stack elements
void display() {
    if(top == -1) {
        return;  // Nothing to display
    }

    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Read number of operations
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int choice;

        // Read operation type
        scanf("%d", &choice);

        if(choice == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if(choice == 2) {
            pop();
        }
        else if(choice == 3) {
            display();
        }
    }

    return 0;
}
