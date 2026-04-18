/*
 * Day 85: Find Minimum in Rotated Sorted Array
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int findMin(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return arr[left];
}

int main() {
    printf("=== Day 85: Find Minimum in Rotated Array ===\n\n");
    
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    
    printf("Minimum element: %d\n", findMin(arr, n));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
