/*
 * Day 83: Search in Rotated Sorted Array
 * 
 * Problem: Search element in rotated sorted array
 * Example: [4,5,6,7,0,1,2] rotated at index 4
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>

int searchRotated(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        // Check which half is sorted
        if (arr[left] <= arr[mid]) {
            // Left half is sorted
            if (target >= arr[left] && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (target > arr[mid] && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

int main() {
    printf("=== Day 83: Search in Rotated Sorted Array ===\n\n");
    
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    int target = 0;
    int result = searchRotated(arr, n, target);
    printf("Search %d: %s at index %d\n", target, 
           result != -1 ? "Found" : "Not found", result);
    
    target = 3;
    result = searchRotated(arr, n, target);
    printf("Search %d: %s\n", target, result != -1 ? "Found" : "Not found");
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
