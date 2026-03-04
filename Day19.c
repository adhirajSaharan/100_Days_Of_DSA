#include <stdio.h>
#include <stdlib.h>  // For abs()

int main() {
    int n;

    // Read size of the array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Variables to store the best pair
    int minSum = 1000000;  // Start with a large value
    int num1, num2;

    // Check all possible pairs
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];

            // If this pair has sum closer to zero
            if(abs(sum) < abs(minSum)) {
                minSum = sum;
                num1 = arr[i];
                num2 = arr[j];
            }
        }
    }

    // Print the pair
    printf("%d %d", num1, num2);

    return 0;
}
