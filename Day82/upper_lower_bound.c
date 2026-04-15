/*
 * Day 82: Upper Bound and Lower Bound
 * 
 * Lower Bound: First position where element >= target
 * Upper Bound: First position where element > target
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

// Lower bound: first element >= target
int lowerBound(int arr[], int n, int target) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Upper bound: first element > target
int upperBound(int arr[], int n, int target) {
    int left = 0, right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Count occurrences of target
int countOccurrences(int arr[], int n, int target) {
    int lb = lowerBound(arr, n, target);
    int ub = upperBound(arr, n, target);
    return ub - lb;
}

int main() {
    printf("=== Day 82: Upper and Lower Bound ===\n\n");
    
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    int target = 2;
    printf("Target: %d\n", target);
    printf("Lower Bound: %d\n", lowerBound(arr, n, target));
    printf("Upper Bound: %d\n", upperBound(arr, n, target));
    printf("Count: %d\n", countOccurrences(arr, n, target));
    
    printf("\n=== Test Case 2 ===\n");
    target = 5;
    printf("Target: %d\n", target);
    printf("Lower Bound: %d\n", lowerBound(arr, n, target));
    printf("Upper Bound: %d\n", upperBound(arr, n, target));
    printf("Count: %d\n", countOccurrences(arr, n, target));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
