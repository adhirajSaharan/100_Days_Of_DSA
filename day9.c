/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j;
    char temp;

    // Read the string (no spaces, lowercase letters only)
    scanf("%s", str);

    // Find length of the string
    j = strlen(str) - 1;   // last index

    // Reverse the string using swapping
    for (i = 0; i < j; i++, j--) {
        temp = str[i];     // store first character
        str[i] = str[j];   // move last character to front
        str[j] = temp;     // move stored character to end
    }

    // Print the mirrored string
    printf("%s", str);

    return 0;
}
