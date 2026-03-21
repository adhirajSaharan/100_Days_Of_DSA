#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

/* Stack to store operands */
int stack[MAX];
int top = -1;

/* Push element into stack */
void push(int value) {
    stack[++top] = value;
}

/* Pop element from stack */
int pop() {
    return stack[top--];
}

/* Function to evaluate Reverse Polish Notation */
int evalRPN(char *tokens[], int n) {
    int a, b, result;

    for (int i = 0; i < n; i++) {

        /* Check if token is an operator */
        if (strcmp(tokens[i], "+") == 0 ||
            strcmp(tokens[i], "-") == 0 ||
            strcmp(tokens[i], "*") == 0 ||
            strcmp(tokens[i], "/") == 0) {

            /* Pop two operands from stack */
            b = pop();
            a = pop();

            /* Perform the operation */
            if (strcmp(tokens[i], "+") == 0)
                result = a + b;

            else if (strcmp(tokens[i], "-") == 0)
                result = a - b;

            else if (strcmp(tokens[i], "*") == 0)
                result = a * b;

            else if (strcmp(tokens[i], "/") == 0)
                result = a / b;   // Integer division truncates toward zero in C

            /* Push result back to stack */
            push(result);
        }
        else {
            /* If token is a number, convert string to integer and push */
            push(atoi(tokens[i]));
        }
    }

    /* Final result will be at top of stack */
    return pop();
}

int main() {

    /* Example input */
    char *tokens[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int n = sizeof(tokens) / sizeof(tokens[0]);

    int result = evalRPN(tokens, n);

    printf("Output: %d\n", result);

    return 0;
}
