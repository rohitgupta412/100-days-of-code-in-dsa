/*
 * Day 89: Allocate Minimum Pages
 * Allocate books to students to minimize maximum pages
 * Time Complexity: O(n log(sum))
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool isPossible(int books[], int n, int students, int maxPages) {
    int studentCount = 1;
    int currentPages = 0;
    
    for (int i = 0; i < n; i++) {
        if (books[i] > maxPages) return false;
        
        if (currentPages + books[i] > maxPages) {
            studentCount++;
            currentPages = books[i];
            if (studentCount > students) return false;
        } else {
            currentPages += books[i];
        }
    }
    
    return true;
}

int allocateBooks(int books[], int n, int students) {
    if (students > n) return -1;
    
    int sum = 0, maxBook = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i];
        if (books[i] > maxBook) maxBook = books[i];
    }
    
    int left = maxBook, right = sum, result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (isPossible(books, n, students, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result;
}

int main() {
    printf("=== Day 89: Allocate Minimum Pages ===\n\n");
    
    int books[] = {12, 34, 67, 90};
    int n = sizeof(books) / sizeof(books[0]);
    int students = 2;
    
    printf("Books: ");
    for (int i = 0; i < n; i++) printf("%d ", books[i]);
    printf("\nStudents: %d\n", students);
    
    printf("Minimum maximum pages: %d\n", allocateBooks(books, n, students));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
