#include <stdio.h>

int main() {
    int m, n;

    // Read number of rows (m) and columns (n)
    scanf("%d %d", &m, &n);

    // Declare matrices
    int matrix1[m][n];
    int matrix2[m][n];
    int result[m][n];

    // Read elements of first matrix
    // We use nested loops to fill row by row
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Read elements of second matrix
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Add corresponding elements of both matrices
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print the resultant matrix
    // Each row should be printed in a new line
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");  // Move to next line after each row
    }

    return 0;
}
