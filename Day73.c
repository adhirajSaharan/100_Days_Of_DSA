#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};  // frequency array

    // Step 1: Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first character with frequency 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            printf("%c", s[i]);
            return 0;
        }
    }

    // If all characters repeat
    printf("$");

    return 0;
}
