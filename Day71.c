#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define DELETED -2

int main() {
    int m, q;

    scanf("%d", &m); // size of hash table
    scanf("%d", &q); // number of operations

    int table[m];

    // Initialize table with EMPTY
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        // Base hash function
        int h = key % m;

        if (strcmp(op, "INSERT") == 0) {

            int i = 0;
            int index;

            // Try quadratic probing
            while (i < m) {
                index = (h + i*i) % m;

                if (table[index] == EMPTY || table[index] == DELETED) {
                    table[index] = key;
                    break;
                }

                i++;
            }

        } else if (strcmp(op, "SEARCH") == 0) {

            int i = 0;
            int index;
            int found = 0;

            while (i < m) {
                index = (h + i*i) % m;

                if (table[index] == EMPTY) {
                    break; // key not present
                }

                if (table[index] == key) {
                    found = 1;
                    break;
                }

                i++;
            }

            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}
