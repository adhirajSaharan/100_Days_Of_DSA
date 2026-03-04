#include <stdio.h>
#include <stdlib.h>

// Define structure for doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    int n;

    // Read number of nodes
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create doubly linked list
    for(int i = 0; i < n; i++) {

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Read data
        scanf("%d", &newNode->data);

        // Initialize pointers
        newNode->prev = NULL;
        newNode->next = NULL;

        // If first node
        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            // Link the new node with previous node
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traverse and print in forward direction
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
