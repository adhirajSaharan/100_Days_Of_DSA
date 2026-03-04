#include <stdio.h>

int main() {
    int m, n;

    // Read number of rows and columns
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Read matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;

    // Primary diagonal elements have row index == column index
    // We must also ensure we do not go out of bounds
    int limit = (m < n) ? m : n;

    for(int i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    // Print the final sum
    printf("%d", sum);

    return 0;
}
