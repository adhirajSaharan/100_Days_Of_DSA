#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in singly linked list
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;

    // Read number of elements
    scanf("%d", &n);

    // If no elements, nothing to print
    if(n <= 0) {
        return 0;
    }

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create linked list
    for(int i = 0; i < n; i++) {

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Read data
        scanf("%d", &newNode->data);

        // Initially, next is NULL
        newNode->next = NULL;

        // If this is the first node
        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            // Attach new node to the list
            temp->next = newNode;
            temp = temp->next;
        }
    }

    // Traverse and print the linked list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
