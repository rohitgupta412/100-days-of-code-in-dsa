#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare integers for qsort
int compareIntegers(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void findClosestToZeroPair(int arr[], int n) {
    // Sort the array in ascending order
    qsort(arr, n, sizeof(int), compareIntegers);

    int left = 0;
    int right = n - 1;
    int min_sum = arr[left] + arr[right];
    int min_left = left;
    int min_right = right;
    
    // Two-pointer approach
    while (left < right) {
        int current_sum = arr[left] + arr[right];

        // If the current sum is closer to zero than the min_sum
        if (abs(current_sum) < abs(min_sum)) {
            min_sum = current_sum;
            min_left = left;
            min_right = right;
        }

        // If sum is exactly zero, we found the optimal pair
        if (current_sum == 0) {
            break;
        }
        // If sum is negative, we need a larger value, so move the left pointer
        else if (current_sum < 0) {
            left++;
        }
        // If sum is positive, we need a smaller value, so move the right pointer
        else {
            right--;
        }
    }

    printf("%d %d\n", arr[min_left], arr[min_right]);
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Read the array elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    findClosestToZeroPair(arr, n);

    free(arr);
    return 0;
}
