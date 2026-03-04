#include <stdio.h>

int main() {
    int n;

    // Read size of the array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Array to mark visited elements
    // visited[i] = 1 means element already counted
    int visited[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;  // Initially, no element is visited
    }

    // Count frequency of each element
    for(int i = 0; i < n; i++) {

        // Skip if already counted
        if(visited[i] == 1)
            continue;

        int count = 1;  // Current element appears at least once

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // Mark as counted
            }
        }

        // Print element and its frequency
        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
