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

    int k;

    // Read number of positions to rotate
    scanf("%d", &k);

    // If k is greater than n, reduce it
    k = k % n;

    // Create a temporary array to store rotated result
    int temp[n];

    // Step 1: Copy last k elements to the beginning
    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Step 2: Copy the remaining elements
    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    // Print the rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
