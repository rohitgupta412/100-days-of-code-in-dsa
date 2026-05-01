/*
 * Day 98: Merge Overlapping Intervals
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void* a, const void* b) {
    Interval* i1 = (Interval*)a;
    Interval* i2 = (Interval*)b;
    return i1->start - i2->start;
}

int mergeIntervals(Interval intervals[], int n, Interval result[]) {
    if (n == 0) return 0;
    
    qsort(intervals, n, sizeof(Interval), compare);
    
    int count = 0;
    result[count] = intervals[0];
    
    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= result[count].end) {
            if (intervals[i].end > result[count].end) {
                result[count].end = intervals[i].end;
            }
        } else {
            result[++count] = intervals[i];
        }
    }
    
    return count + 1;
}

int main() {
    printf("=== Day 98: Merge Overlapping Intervals ===\n\n");
    
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);
    Interval result[100];
    
    printf("Input intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
    
    int count = mergeIntervals(intervals, n, result);
    
    printf("\nMerged intervals:\n");
    for (int i = 0; i < count; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
