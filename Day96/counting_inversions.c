/*
 * Day 96: Counting Inversions
 * Count pairs (i,j) where i<j and arr[i]>arr[j]
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return invCount;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int countInversions(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int));
    int result = mergeSortAndCount(arr, temp, 0, n - 1);
    free(temp);
    return result;
}

int main() {
    printf("=== Day 96: Counting Inversions ===\n\n");
    
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    printf("Number of inversions: %d\n", countInversions(arr, n));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
