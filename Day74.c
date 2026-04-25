#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];     // store input names
    char unique[n][50];    // store unique candidate names
    int count[n];          // store vote counts

    int uniqueCount = 0;

    // Input names
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if name already exists in unique[]
        for (int j = 0; j < uniqueCount; j++) {
            if (strcmp(names[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        // If new candidate, add to unique[]
        if (!found) {
            strcpy(unique[uniqueCount], names[i]);
            count[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    // Find winner
    char winner[50];
    int maxVotes = -1;

    for (int i = 0; i < uniqueCount; i++) {

        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, unique[i]);
        }
        // Tie case → pick lexicographically smaller
        else if (count[i] == maxVotes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    // Output result
    printf("%s %d", winner, maxVotes);

    return 0;
}
