#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int size) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < size; i++) {

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
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    int n, key;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    struct Node* head = createList(n);

    // Read key to count
    scanf("%d", &key);

    int count = 0;

    // Traverse the list and count occurrences
    struct Node* temp = head;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Print the final count
    printf("%d", count);

    return 0;
}
