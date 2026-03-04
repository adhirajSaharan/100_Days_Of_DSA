#include <stdio.h>

int main() {
    int m, n;

    // Read number of rows and columns
    scanf("%d %d", &m, &n);

    // First, a symmetric matrix must be a square matrix
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;   // No need to check further
    }

    // Declare the matrix
    int matrix[m][n];

    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Assume the matrix is symmetric initially
    int isSymmetric = 1;

    // Check if matrix is equal to its transpose
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // If any element does not match its transpose position
            if(matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;  // Not symmetric
                break;
            }
        }
        if(isSymmetric == 0) {
            break;  // Stop checking further
        }
    }

    // Print result based on the flag
    if(isSymmetric) {
        printf("Symmetric Matrix");
    } else {
        printf("Not a Symmetric Matrix");
    }

    return 0;
}
