#include <stdio.h>

int main() {
    int m, n;
    // Read the number of rows (m) and columns (n)
    scanf("%d %d", &m, &n);

    // Check if the matrix is square (necessary for a primary diagonal as defined)
    if (m != n) {
        printf("Error: Matrix must be square (m == n) to have a primary diagonal sum.\n");
        return 1;
    }

    int matrix[m][n];
    int sum = 0;

    // Read the matrix elements from the user
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of the primary diagonal elements
    // The primary diagonal elements are where the row index (i) equals the column index (j)
    for (int i = 0; i < m; i++) {
        sum += matrix[i][i];
    }

    // Print the sum of the primary diagonal elements
    printf("%d\n", sum);

    return 0;
}
