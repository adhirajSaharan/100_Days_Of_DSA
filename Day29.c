#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int size) {
    struct Node *head = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < size; i++) {

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));

        // Read data
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        // Insert node
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

// Function to get length of list
int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, k;

    // Read number of nodes
    scanf("%d", &n);

    // Create linked list
    struct Node* head = createList(n);

    // Read k
    scanf("%d", &k);

    if(head == NULL || k == 0) {
        // If list is empty or no rotation needed
        struct Node* temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Get length of list
    int length = getLength(head);

    // Adjust k if greater than length
    k = k % length;

    if(k == 0) {
        // No rotation needed
        struct Node* temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Find new tail position (n - k - 1)
    struct Node* temp = head;
    for(int i = 0; i < length - k - 1; i++) {
        temp = temp->next;
    }

    // New head is next of new tail
    struct Node* newHead = temp->next;

    // Break the list
    temp->next = NULL;

    // Find last node of new list
    struct Node* last = newHead;
    while(last->next != NULL) {
        last = last->next;
    }

    // Connect last node to old head
    last->next = head;

    // Update head
    head = newHead;

    // Print rotated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
