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

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    struct Node *temp = head, *prev = NULL;

    // If head node itself contains the key
    if(temp != NULL && temp->data == key) {
        head = temp->next;  // Move head
        free(temp);         // Free memory
        return head;
    }

    // Search for the key
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if(temp == NULL) {
        return head;
    }

    // Remove the node
    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int n, key;

    // Read number of elements
    scanf("%d", &n);

    struct Node* head = createList(n);

    // Read key to delete
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteKey(head, key);

    // Print updated list
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
