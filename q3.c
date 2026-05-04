#include <stdio.h>

int main() {
    int n, pos, i;
    int arr[100]; // Assuming a maximum array size of 100

    // Input the number of elements
    printf("Enter the number of elements (n): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input for n.\n");
        return 1;
    }

    // Input the n elements
    printf("Enter %d space-separated integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array elements.\n");
            return 1;
        }
    }

    // Input the 1-based position to delete
    printf("Enter the 1-based position to delete (pos): ");
    if (scanf("%d", &pos) != 1 || pos < 1 || pos > n) {
        printf("Invalid input for position (pos).\n");
        return 1;
    }

    // --- Deletion Logic ---
    // Shift elements from the position to the end
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Decrease the array size
    n--;

    // Output the updated array
    printf("Output: ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
