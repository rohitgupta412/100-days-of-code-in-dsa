#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare_integers(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void count_frequencies(int arr[], int n) {
    // Sort the array to group identical elements
    qsort(arr, n, sizeof(int), compare_integers);

    int count = 1;
    for (int i = 0; i < n; i++) {
        // Check if the next element is the same
        if (i < n - 1 && arr[i] == arr[i+1]) {
            count++;
        } else {
            // If it's a new element or the last one, print the previous element and its count
            printf("%d:%d ", arr[i], count);
            count = 1; // Reset count for the new element
        }
    }
    printf("\n");
}

int main() {
    int n;
    // Read the size of the array
    if (scanf("%d", &n) != 1) return 1;

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Read the n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the function to count and print frequencies
    count_frequencies(arr, n);

    free(arr);
    return 0;
}
