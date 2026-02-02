/*
Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/

#include <stdio.h>

int main() {
    int n, pos;

    //taking the size of the array
    scanf("%d",&n);
    //make array
    int arr[n];
    //taking array elements
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //taking position to delete from (1-based)
    scanf("%d",&pos);

    //shifting elements to the left starting from the deletion point
    //pos-1 is used because array indexing starts from 0
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // printing updated array (size becomes n-1)
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
