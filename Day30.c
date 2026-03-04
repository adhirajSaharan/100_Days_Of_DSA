#include <stdio.h>
#include <stdlib.h>

// Define structure for polynomial term
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

int main() {
    int n;

    // Read number of terms
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list for polynomial
    for(int i = 0; i < n; i++) {

        // Allocate memory for new term
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Read coefficient and exponent
        scanf("%d %d", &newNode->coefficient, &newNode->exponent);

        newNode->next = NULL;

        // Insert node into list
        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Traverse and print polynomial
    temp = head;

    while(temp != NULL) {

        // Print term based on exponent
        if(temp->exponent > 1) {
            printf("%dx^%d", temp->coefficient, temp->exponent);
        }
        else if(temp->exponent == 1) {
            printf("%dx", temp->coefficient);
        }
        else { // exponent == 0
            printf("%d", temp->coefficient);
        }

        // Print " + " if not the last term
        if(temp->next != NULL) {
            printf(" + ");
        }

        temp = temp->next;
    }

    return 0;
}
