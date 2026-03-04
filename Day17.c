#include <stdio.h>

int main() {
    int n;

    // Read the size of the array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is both max and min
    int max = arr[0];
    int min = arr[0];

    // Traverse the array to find actual max and min
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];   // Update maximum
        }

        if(arr[i] < min) {
            min = arr[i];   // Update minimum
        }
    }

    // Print results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
