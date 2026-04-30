/*
 * Day 97: Meeting Rooms Scheduling
 * Check if person can attend all meetings
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void* a, const void* b) {
    Meeting* m1 = (Meeting*)a;
    Meeting* m2 = (Meeting*)b;
    return m1->start - m2->start;
}

bool canAttendMeetings(Meeting meetings[], int n) {
    qsort(meetings, n, sizeof(Meeting), compare);
    
    for (int i = 1; i < n; i++) {
        if (meetings[i].start < meetings[i-1].end) {
            return false;
        }
    }
    
    return true;
}

int main() {
    printf("=== Day 97: Meeting Rooms ===\n\n");
    
    Meeting meetings[] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(meetings) / sizeof(meetings[0]);
    
    printf("Meetings:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d, %d] ", meetings[i].start, meetings[i].end);
    }
    printf("\n");
    
    printf("Can attend all meetings? %s\n", 
           canAttendMeetings(meetings, n) ? "Yes" : "No");
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
