/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include <stdio.h>

int main() {
    int n;
    
    // Read size of array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements (already sorted)
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If array is empty, nothing to print
    if (n == 0) {
        return 0;
    }

    // j will store the index of the last unique element
    int j = 0;

    // Traverse from second element to end
    for (int i = 1; i < n; i++) {
        // If current element is different from last unique element
        if (arr[i] != arr[j]) {
            j++;              // move to next position
            arr[j] = arr[i];  // store unique element
        }
    }

    // Print unique elements
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
