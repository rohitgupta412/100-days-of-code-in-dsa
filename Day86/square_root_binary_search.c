/*
 * Day 86: Square Root using Binary Search
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    
    int left = 1, right = x, result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (mid <= x / mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    printf("=== Day 86: Square Root using Binary Search ===\n\n");
    
    int nums[] = {4, 8, 16, 25, 30, 50};
    int n = sizeof(nums) / sizeof(nums[0]);
    
    for (int i = 0; i < n; i++) {
        printf("sqrt(%d) = %d\n", nums[i], mySqrt(nums[i]));
    }
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
