/*
 * Day 90: Painter Partition Problem
 * Allocate boards to painters to minimize time
 * Time Complexity: O(n log(sum))
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool isPossible(int boards[], int n, int painters, int maxTime) {
    int painterCount = 1;
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return false;
        
        if (currentTime + boards[i] > maxTime) {
            painterCount++;
            currentTime = boards[i];
            if (painterCount > painters) return false;
        } else {
            currentTime += boards[i];
        }
    }
    
    return true;
}

int painterPartition(int boards[], int n, int painters) {
    int sum = 0, maxBoard = 0;
    for (int i = 0; i < n; i++) {
        sum += boards[i];
        if (boards[i] > maxBoard) maxBoard = boards[i];
    }
    
    int left = maxBoard, right = sum, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isPossible(boards, n, painters, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    printf("=== Day 90: Painter Partition Problem ===\n\n");
    
    int boards[] = {10, 20, 30, 40};
    int n = sizeof(boards) / sizeof(boards[0]);
    int painters = 2;
    
    printf("Boards: ");
    for (int i = 0; i < n; i++) printf("%d ", boards[i]);
    printf("\nPainters: %d\n", painters);
    
    printf("Minimum time: %d\n", painterPartition(boards, n, painters));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
