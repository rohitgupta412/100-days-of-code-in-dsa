#include <stdio.h>

// Function to check if a matrix is an identity matrix
int isIdentity(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check diagonal elements (where i == j)
            if (i == j && matrix[i][j] != 1) {
                return 0; // Not an identity matrix
            }
            // Check non-diagonal elements (where i != j)
            if (i != j && matrix[i][j] != 0) {
                return 0; // Not an identity matrix
            }
        }
    }
    return 1; // It is an identity matrix
}

int main() {
    int n;

    // Read the size of the matrix
    // printf("Enter the size of the square matrix (n): ");
    if (scanf("%d", &n) != 1) {
        // Handle potential input error for n
        return 1; 
    }

    int matrix[n][n]; // Declare a variable size array (C99 feature)

    // Read the matrix elements
    // printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                // Handle potential input error for matrix elements
                return 1;
            }
        }
    }

    // Check and print the result
    if (isIdentity(n, matrix)) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }

    return 0;
}
