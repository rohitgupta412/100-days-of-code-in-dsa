/*
 * Day 73: First Non-Repeating Character
 * 
 * Problem: Find the first character that appears only once in a string
 * 
 * Time Complexity: O(n) - where n is string length
 * Space Complexity: O(1) - fixed size hash table
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR 256

// Function to find first non-repeating character
char firstNonRepeatingChar(char* str) {
    int count[MAX_CHAR] = {0};
    
    // Count occurrences of each character
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    // Find first character with count == 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0';  // No non-repeating character
}

// Function to find first non-repeating character with index
void firstNonRepeatingWithIndex(char* str) {
    int count[MAX_CHAR] = {0};
    int index[MAX_CHAR];
    
    // Initialize indices to -1
    for (int i = 0; i < MAX_CHAR; i++) {
        index[i] = -1;
    }
    
    // Store first occurrence index and count
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        count[ch]++;
        
        if (index[ch] == -1) {
            index[ch] = i;
        }
    }
    
    // Find minimum index with count == 1
    int minIndex = -1;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (count[i] == 1) {
            if (minIndex == -1 || index[i] < minIndex) {
                minIndex = index[i];
            }
        }
    }
    
    if (minIndex != -1) {
        printf("First non-repeating character: '%c' at index %d\n", 
               str[minIndex], minIndex);
    } else {
        printf("No non-repeating character found\n");
    }
}

// Function to print all non-repeating characters
void printAllNonRepeating(char* str) {
    int count[MAX_CHAR] = {0};
    
    // Count occurrences
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    printf("All non-repeating characters: ");
    bool found = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            printf("'%c' ", str[i]);
            found = true;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

// Main function
int main() {
    printf("=== Day 73: First Non-Repeating Character ===\n\n");
    
    // Test Case 1
    char str1[] = "geeksforgeeks";
    printf("String: \"%s\"\n", str1);
    char result = firstNonRepeatingChar(str1);
    if (result != '\0') {
        printf("First non-repeating character: '%c'\n", result);
    } else {
        printf("No non-repeating character\n");
    }
    firstNonRepeatingWithIndex(str1);
    printAllNonRepeating(str1);
    
    // Test Case 2
    printf("\n=== Test Case 2 ===\n");
    char str2[] = "hello";
    printf("String: \"%s\"\n", str2);
    result = firstNonRepeatingChar(str2);
    if (result != '\0') {
        printf("First non-repeating character: '%c'\n", result);
    } else {
        printf("No non-repeating character\n");
    }
    firstNonRepeatingWithIndex(str2);
    printAllNonRepeating(str2);
    
    // Test Case 3
    printf("\n=== Test Case 3 ===\n");
    char str3[] = "aabbcc";
    printf("String: \"%s\"\n", str3);
    result = firstNonRepeatingChar(str3);
    if (result != '\0') {
        printf("First non-repeating character: '%c'\n", result);
    } else {
        printf("No non-repeating character\n");
    }
    firstNonRepeatingWithIndex(str3);
    printAllNonRepeating(str3);
    
    // Test Case 4
    printf("\n=== Test Case 4 ===\n");
    char str4[] = "leetcode";
    printf("String: \"%s\"\n", str4);
    result = firstNonRepeatingChar(str4);
    if (result != '\0') {
        printf("First non-repeating character: '%c'\n", result);
    } else {
        printf("No non-repeating character\n");
    }
    firstNonRepeatingWithIndex(str4);
    printAllNonRepeating(str4);
    
    // Test Case 5
    printf("\n=== Test Case 5 ===\n");
    char str5[] = "aabbccdd";
    printf("String: \"%s\"\n", str5);
    result = firstNonRepeatingChar(str5);
    if (result != '\0') {
        printf("First non-repeating character: '%c'\n", result);
    } else {
        printf("No non-repeating character\n");
    }
    firstNonRepeatingWithIndex(str5);
    printAllNonRepeating(str5);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 73: First Non-Repeating Character ===
 * 
 * String: "geeksforgeeks"
 * First non-repeating character: 'f'
 * First non-repeating character: 'f' at index 5
 * All non-repeating characters: 'f' 'o' 'r' 
 * 
 * === Test Case 2 ===
 * String: "hello"
 * First non-repeating character: 'h'
 * First non-repeating character: 'h' at index 0
 * All non-repeating characters: 'h' 'e' 'o' 
 * 
 * === Test Case 3 ===
 * String: "aabbcc"
 * No non-repeating character
 * No non-repeating character found
 * All non-repeating characters: None
 * 
 * === Test Case 4 ===
 * String: "leetcode"
 * First non-repeating character: 'l'
 * First non-repeating character: 'l' at index 0
 * All non-repeating characters: 'l' 't' 'c' 'o' 'd' 
 * 
 * === Test Case 5 ===
 * String: "aabbccdd"
 * No non-repeating character
 * No non-repeating character found
 * All non-repeating characters: None
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - two passes through string
 * - Space Complexity: O(1) - fixed size array (256 chars)
 * 
 * Key Points:
 * 1. Use hash table to count character occurrences
 * 2. Find first character with count == 1
 * 3. Common interview question
 * 4. Applications: Stream processing, data deduplication
 */
