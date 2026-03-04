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

    int count = 0;

    // Check all possible subarrays
    for(int i = 0; i < n; i++) {

        int sum = 0;  // Reset sum for each starting point

        for(int j = i; j < n; j++) {

            sum += arr[j];  // Add current element

            // If sum becomes zero, increase count
            if(sum == 0) {
                count++;
            }
        }
    }

    // Print total number of zero-sum subarrays
    printf("%d", count);

    return 0;
}
