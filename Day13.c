#include <stdio.h>

int main() {
    int r, c;

    // Read number of rows and columns
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    // Read matrix elements
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Define boundary variables
    int top = 0;        // Top row index
    int bottom = r - 1; // Bottom row index
    int left = 0;       // Left column index
    int right = c - 1;  // Right column index

    // Continue traversal until all layers are covered
    while(top <= bottom && left <= right) {

        // Traverse from left to right (top row)
        for(int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;  // Move top boundary downward

        // Traverse from top to bottom (right column)
        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;  // Move right boundary leftward

        // Traverse from right to left (bottom row), if rows remain
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;  // Move bottom boundary upward
        }

        // Traverse from bottom to top (left column), if columns remain
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;  // Move left boundary rightward
        }
    }

    return 0;
}
