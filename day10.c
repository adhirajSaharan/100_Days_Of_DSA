/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int left, right;
    int isPalindrome = 1;   // assume string is palindrome

    // Read the string (no spaces)
    scanf("%s", s);

    // Initialize pointers
    left = 0;
    right = strlen(s) - 1;

    // Compare characters from both ends
    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = 0;   // mismatch found
            break;
        }
        left++;
        right--;
    }

    // Print result
    if (isPalindrome)
        printf("YES");
    else
        printf("NO");

    return 0;
}
