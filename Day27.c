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

// Function to get length of linked list
int getLength(struct Node* head) {
    int length = 0;
    while(head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection point
int findIntersection(struct Node* head1, struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Make both lists equal in remaining length
    while(len1 > len2) {
        head1 = head1->next;
        len1--;
    }

    while(len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    // Traverse both lists together
    while(head1 != NULL && head2 != NULL) {

        if(head1->data == head2->data) {
            return head1->data;  // Intersection found
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;  // No intersection
}

int main() {
    int n, m;

    // Read first list
    scanf("%d", &n);
    struct Node* list1 = createList(n);

    // Read second list
    scanf("%d", &m);
    struct Node* list2 = createList(m);

    // Find intersection
    int result = findIntersection(list1, list2);

    if(result == -1) {
        printf("No Intersection");
    }
    else {
        printf("%d", result);
    }

    return 0;
}
