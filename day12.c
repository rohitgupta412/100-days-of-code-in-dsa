#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int isSymmetric = 1;

    // Read rows and columns
    scanf("%d %d", &m, &n);

    // Read matrix elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric)
            break;
    }

    // Output result
    if (isSymmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}
