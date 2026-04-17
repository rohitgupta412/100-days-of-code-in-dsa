/*
 * Day 84: Find Peak Element
 * Peak element is greater than its neighbors
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int findPeak(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int main() {
    printf("=== Day 84: Find Peak Element ===\n\n");
    
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    int peak = findPeak(arr, n);
    printf("Peak element at index %d: %d\n", peak, arr[peak]);
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
