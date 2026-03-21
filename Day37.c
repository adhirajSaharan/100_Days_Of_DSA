#include <stdio.h>

#define MAX 100

int pq[MAX];   // array to store priority queue
int size = 0;  // current number of elements

/* Function to insert element into priority queue */
void insert(int value) {

    // Check overflow
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    pq[size] = value;  // insert at end
    size++;
}

/* Function to delete element with highest priority (smallest value) */
int delete() {

    if (size == 0)      // if queue empty
        return -1;

    int minIndex = 0;

    // find index of smallest element
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    int deleted = pq[minIndex];  // element to delete

    // shift elements left to fill gap
    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;

    return deleted;
}

/* Function to peek element with highest priority */
int peek() {

    if (size == 0)
        return -1;

    int min = pq[0];

    // find smallest value
    for (int i = 1; i < size; i++) {
        if (pq[i] < min)
            min = pq[i];
    }

    return min;
}

int main() {

    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {

        scanf("%s", op);

        // insert operation
        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        }

        // delete operation
        else if (op[0] == 'd') {
            printf("%d\n", delete());
        }

        // peek operation
        else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }

    return 0;
}
