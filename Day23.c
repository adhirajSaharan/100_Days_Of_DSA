#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list
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

// Function to merge two sorted lists
struct Node* merge(struct Node* l1, struct Node* l2) {

    // Dummy node to simplify merging
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Compare elements of both lists
    while(l1 != NULL && l2 != NULL) {

        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    // Attach remaining elements
    if(l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m;

    // Read first list size
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    // Read second list size
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // Merge the two lists
    struct Node* merged = merge(list1, list2);

    // Print merged list
    struct Node* temp = merged;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
