#include <stdio.h>
#include <limits.h> // Required for INT_MAX and INT_MIN

int main() {
    int n, i;
    int max_val = INT_MIN; // Initialize max with the smallest possible integer value
    int min_val = INT_MAX; // Initialize min with the largest possible integer value

    // Read the number of elements
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for n.\n");
        return 1;
    }

    int arr[n]; // Declare an array of size n (Variable Length Array, a C99 feature)

    // Read the elements of the array
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array elements.\n");
            return 1;
        }
    }

    // Find the maximum and minimum values
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i]; // Update max if current element is greater
        }
        if (arr[i] < min_val) {
            min_val = arr[i]; // Update min if current element is smaller
        }
    }

    // Print the results
    printf("Max: %d\n", max_val);
    printf("Min: %d\n", min_val);

    return 0;
}
