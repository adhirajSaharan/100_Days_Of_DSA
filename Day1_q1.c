/* Q1
Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/
#include <stdio.h>

int main() {
    int n, pos, x;
    // taking size of array
    scanf("%d", &n);
    int arr[n + 1];  // size n+1 because one extra element will be inserted
    // taking array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // taking position (1-based)
    scanf("%d", &pos);

    // taking element to insert
    scanf("%d", &x);

    // shifting elements to the right from the end
    // start from last element and go till position
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    // inserting the element at correct position
    arr[pos - 1] = x;
    // printing updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

