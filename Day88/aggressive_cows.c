/*
 * Day 88: Aggressive Cows Problem
 * Place cows in stalls to maximize minimum distance
 * Time Complexity: O(n log n + n log(max-min))
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool canPlaceCows(int stalls[], int n, int cows, int minDist) {
    int count = 1;
    int lastPos = stalls[0];
    
    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
            if (count >= cows) return true;
        }
    }
    
    return false;
}

int aggressiveCows(int stalls[], int n, int cows) {
    qsort(stalls, n, sizeof(int), compare);
    
    int left = 1;
    int right = stalls[n-1] - stalls[0];
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canPlaceCows(stalls, n, cows, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    printf("=== Day 88: Aggressive Cows ===\n\n");
    
    int stalls[] = {1, 2, 4, 8, 9};
    int n = sizeof(stalls) / sizeof(stalls[0]);
    int cows = 3;
    
    printf("Stalls: ");
    for (int i = 0; i < n; i++) printf("%d ", stalls[i]);
    printf("\nCows: %d\n", cows);
    
    printf("Maximum minimum distance: %d\n", aggressiveCows(stalls, n, cows));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
