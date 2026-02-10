/*
Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
*/
#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    // Base case: any number raised to power 0 is 1
    if (b == 0)
        return 1;

    // Recursive case: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Read input values
    scanf("%d %d", &a, &b);

    // Print result
    printf("%d", power(a, b));

    return 0;
}
