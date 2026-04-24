#include <stdio.h>

// Function to check Min-Heap property using array representation
int isMinHeap(int arr[], int n) {

    // Only need to check non-leaf nodes
    // Last non-leaf node = (n/2 - 1)
    for (int i = 0; i <= (n/2 - 1); i++) {

        int left = 2*i + 1;
        int right = 2*i + 2;

        // Check with left child
        if (left < n && arr[i] > arr[left])
            return 0;

        // Check with right child
        if (right < n && arr[i] > arr[right])
            return 0;
    }

    return 1;  // valid min-heap
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Read level-order traversal (array form)
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap
    if (isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
