#include <stdio.h>

int main() {
    int n;

    // Read the size of the square matrix
    scanf("%d", &n);

    int matrix[n][n];

    // Read matrix elements
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Assume the matrix is an identity matrix initially
    int isIdentity = 1;

    // Check all elements of the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            // If we are on diagonal (i == j)
            if(i == j) {
                // Diagonal elements must be 1
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            }
            // If we are on non-diagonal elements
            else {
                // Non-diagonal elements must be 0
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0) {
            break;  // Stop checking if already not identity
        }
    }

    // Print result
    if(isIdentity) {
        printf("Identity Matrix");
    } else {
        printf("Not an Identity Matrix");
    }

    return 0;
}
