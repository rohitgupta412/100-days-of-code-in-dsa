/*
 * Day 75: Largest Subarray with Zero Sum
 * 
 * Problem: Find length of longest subarray with sum = 0
 * 
 * Time Complexity: O(n) - using hash table
 * Space Complexity: O(n) - for hash table
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

// Structure for hash table entry
typedef struct {
    int sum;
    int index;
    int used;
} HashEntry;

// Function to find largest subarray with zero sum
int largestZeroSumSubarray(int arr[], int n) {
    HashEntry hashTable[MAX_SIZE];
    
    // Initialize hash table
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable[i].used = 0;
    }
    
    int maxLen = 0;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        // If sum is 0, subarray from 0 to i has zero sum
        if (sum == 0) {
            maxLen = i + 1;
        }
        
        // Check if sum has been seen before
        int hashIndex = (sum % MAX_SIZE + MAX_SIZE) % MAX_SIZE;
        
        // Linear probing for collision resolution
        while (hashTable[hashIndex].used && hashTable[hashIndex].sum != sum) {
            hashIndex = (hashIndex + 1) % MAX_SIZE;
        }
        
        if (hashTable[hashIndex].used) {
            // Sum seen before, calculate length
            int len = i - hashTable[hashIndex].index;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            // First time seeing this sum
            hashTable[hashIndex].sum = sum;
            hashTable[hashIndex].index = i;
            hashTable[hashIndex].used = 1;
        }
    }
    
    return maxLen;
}

// Function to print subarray with zero sum
void printZeroSumSubarray(int arr[], int n) {
    HashEntry hashTable[MAX_SIZE];
    
    // Initialize hash table
    for (int i = 0; i < MAX_SIZE; i++) {
        hashTable[i].used = 0;
    }
    
    int maxLen = 0;
    int sum = 0;
    int startIndex = -1, endIndex = -1;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        if (sum == 0) {
            if (i + 1 > maxLen) {
                maxLen = i + 1;
                startIndex = 0;
                endIndex = i;
            }
        }
        
        int hashIndex = (sum % MAX_SIZE + MAX_SIZE) % MAX_SIZE;
        
        while (hashTable[hashIndex].used && hashTable[hashIndex].sum != sum) {
            hashIndex = (hashIndex + 1) % MAX_SIZE;
        }
        
        if (hashTable[hashIndex].used) {
            int len = i - hashTable[hashIndex].index;
            if (len > maxLen) {
                maxLen = len;
                startIndex = hashTable[hashIndex].index + 1;
                endIndex = i;
            }
        } else {
            hashTable[hashIndex].sum = sum;
            hashTable[hashIndex].index = i;
            hashTable[hashIndex].used = 1;
        }
    }
    
    if (maxLen > 0) {
        printf("Largest zero sum subarray: [");
        for (int i = startIndex; i <= endIndex; i++) {
            printf("%d", arr[i]);
            if (i < endIndex) printf(", ");
        }
        printf("]\n");
        printf("Length: %d\n", maxLen);
    } else {
        printf("No zero sum subarray found\n");
    }
}

// Main function
int main() {
    printf("=== Day 75: Largest Subarray with Zero Sum ===\n\n");
    
    // Test Case 1
    printf("Test Case 1:\n");
    int arr1[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("Array: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    int maxLen = largestZeroSumSubarray(arr1, n1);
    printf("Length of largest zero sum subarray: %d\n", maxLen);
    printZeroSumSubarray(arr1, n1);
    
    // Test Case 2
    printf("\n=== Test Case 2 ===\n");
    int arr2[] = {1, 2, 3, -3, -2, -1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("Array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    
    maxLen = largestZeroSumSubarray(arr2, n2);
    printf("Length of largest zero sum subarray: %d\n", maxLen);
    printZeroSumSubarray(arr2, n2);
    
    // Test Case 3
    printf("\n=== Test Case 3 ===\n");
    int arr3[] = {1, 0, -1, 0, 1, -1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    printf("Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
    
    maxLen = largestZeroSumSubarray(arr3, n3);
    printf("Length of largest zero sum subarray: %d\n", maxLen);
    printZeroSumSubarray(arr3, n3);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 75: Largest Subarray with Zero Sum ===
 * 
 * Test Case 1:
 * Array: 15 -2 2 -8 1 7 10 23 
 * Length of largest zero sum subarray: 5
 * Largest zero sum subarray: [-2, 2, -8, 1, 7]
 * Length: 5
 * 
 * === Test Case 2 ===
 * Array: 1 2 3 -3 -2 -1 
 * Length of largest zero sum subarray: 6
 * Largest zero sum subarray: [1, 2, 3, -3, -2, -1]
 * Length: 6
 * 
 * === Test Case 3 ===
 * Array: 1 0 -1 0 1 -1 
 * Length of largest zero sum subarray: 6
 * Largest zero sum subarray: [1, 0, -1, 0, 1, -1]
 * Length: 6
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - single pass with hash table
 * - Space Complexity: O(n) - for hash table
 * 
 * Key Points:
 * 1. Use cumulative sum and hash table
 * 2. If sum repeats, subarray between has zero sum
 * 3. If sum is 0, subarray from start has zero sum
 * 4. Common interview problem
 */
