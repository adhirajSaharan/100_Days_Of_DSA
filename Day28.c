#include <stdio.h>
#include <stdlib.h>

// Define structure for circular linked list node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;

    // Read number of nodes
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Create circular linked list
    for(int i = 0; i < n; i++) {

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Read data
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        // If first node
        if(head == NULL) {
            head = newNode;
            temp = head;
        }
        else {
            // Link new node
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make the list circular
    if(temp != NULL) {
        temp->next = head;
    }

    // Traverse circular linked list
    if(head != NULL) {
        temp = head;

        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}
