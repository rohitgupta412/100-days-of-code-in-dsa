#include <stdio.h>

void printSpiralOrder(int r, int c, int matrix[r][c]) {
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;
    int totalElements = r * c;
    int count = 0;

    while (top <= bottom && left <= right) {
        // Traverse Right (Top Row)
        for (int i = left; i <= right && count < totalElements; ++i) {
            printf("%d ", matrix[top][i]);
            count++;
        }
        top++;

        // Traverse Down (Right Column)
        for (int i = top; i <= bottom && count < totalElements; ++i) {
            printf("%d ", matrix[i][right]);
            count++;
        }
        right--;

        // Traverse Left (Bottom Row)
        for (int i = right; i >= left && count < totalElements; --i) {
            printf("%d ", matrix[bottom][i]);
            count++;
        }
        bottom--;

        // Traverse Up (Left Column)
        for (int i = bottom; i >= top && count < totalElements; --i) {
            printf("%d ", matrix[i][left]);
            count++;
        }
        left++;
    }
    printf("\n");
}

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;
    
    int matrix[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printSpiralOrder(r, c, matrix);

    return 0;
}
