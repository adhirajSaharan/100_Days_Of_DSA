#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Array to store first occurrence of prefix sums
    int map[20001];

    // Initialize with -2 (means not seen)
    for (int i = 0; i < 20001; i++) {
        map[i] = -2;
    }

    int offset = 10000;   // to handle negative sums

    // Prefix sum 0 at index -1
    map[offset] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int key = prefixSum + offset;

        // If seen before → zero sum subarray exists
        if (map[key] != -2) {
            int length = i - map[key];
            if (length > maxLen) {
                maxLen = length;
            }
        } else {
            // Store first occurrence
            map[key] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}
