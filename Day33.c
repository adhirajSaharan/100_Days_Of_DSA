#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Function to push an operator onto the stack */
void push(char x) {
    stack[++top] = x;
}

/* Function to pop an operator from the stack */
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

/* Function to check precedence of operators */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    /* Read infix expression */
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        /* If operand, add it directly to postfix */
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        /* If '(', push to stack */
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        /* If ')', pop until '(' is found */
        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }

        /* If operator, pop operators with higher or equal precedence */
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    /* Pop remaining operators from stack */
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // end postfix string

    /* Print postfix expression */
    printf("%s", postfix);

    return 0;
}
