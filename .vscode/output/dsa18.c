#include <stdio.h>

void rotateRight(int arr[], int n, int k) {
    // Handle cases where k might be larger than n
    k = k % n;

    if (k == 0) {
        return; // No rotation needed
    }

    // Create a temporary array of size k to store the last k elements
    int temp[k];

    // Copy the last k elements into temp
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the remaining n-k elements to the right
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }

    // Copy the elements from temp to the beginning of the original array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n, k;

    // Read input n
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    // Read n integers
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Read input k
    if (scanf("%d", &k) != 1) return 1;

    // Rotate the array
    rotateRight(arr, n, k);

    // Print the rotated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
