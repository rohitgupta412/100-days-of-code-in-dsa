/*
 * Day 72: First Repeated Character
 * 
 * Problem: Find the first character that repeats in a string
 * 
 * Time Complexity: O(n) - where n is string length
 * Space Complexity: O(1) - fixed size hash table (26 letters)
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_CHAR 256

// Function to find first repeated character using hash table
char firstRepeatedChar(char* str) {
    int count[MAX_CHAR] = {0};
    
    // Count occurrences of each character
    for (int i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    // Find first character with count > 1
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] > 1) {
            return str[i];
        }
    }
    
    return '\0';  // No repeated character
}

// Function to find first repeated character (case insensitive)
char firstRepeatedCharIgnoreCase(char* str) {
    int count[26] = {0};
    
    // Count occurrences (case insensitive)
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            count[tolower(str[i]) - 'a']++;
        }
    }
    
    // Find first repeated character
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (count[tolower(str[i]) - 'a'] > 1) {
                return str[i];
            }
        }
    }
    
    return '\0';
}

// Function to find first repeated character with its index
void firstRepeatedWithIndex(char* str) {
    int firstIndex[MAX_CHAR];
    
    // Initialize all indices to -1
    for (int i = 0; i < MAX_CHAR; i++) {
        firstIndex[i] = -1;
    }
    
    int minIndex = -1;
    
    // Traverse string from right to left
    for (int i = strlen(str) - 1; i >= 0; i--) {
        unsigned char ch = str[i];
        
        // If character seen before
        if (firstIndex[ch] != -1) {
            minIndex = i;
        }
        
        firstIndex[ch] = i;
    }
    
    if (minIndex != -1) {
        printf("First repeated character: '%c' at index %d\n", 
               str[minIndex], minIndex);
    } else {
        printf("No repeated character found\n");
    }
}

// Main function
int main() {
    printf("=== Day 72: First Repeated Character ===\n\n");
    
    // Test Case 1
    char str1[] = "geeksforgeeks";
    printf("String: \"%s\"\n", str1);
    char result = firstRepeatedChar(str1);
    if (result != '\0') {
        printf("First repeated character: '%c'\n", result);
    } else {
        printf("No repeated character\n");
    }
    firstRepeatedWithIndex(str1);
    
    // Test Case 2
    printf("\n=== Test Case 2 ===\n");
    char str2[] = "hello";
    printf("String: \"%s\"\n", str2);
    result = firstRepeatedChar(str2);
    if (result != '\0') {
        printf("First repeated character: '%c'\n", result);
    } else {
        printf("No repeated character\n");
    }
    firstRepeatedWithIndex(str2);
    
    // Test Case 3
    printf("\n=== Test Case 3 ===\n");
    char str3[] = "abcdef";
    printf("String: \"%s\"\n", str3);
    result = firstRepeatedChar(str3);
    if (result != '\0') {
        printf("First repeated character: '%c'\n", result);
    } else {
        printf("No repeated character\n");
    }
    firstRepeatedWithIndex(str3);
    
    // Test Case 4: Case insensitive
    printf("\n=== Test Case 4 (Case Insensitive) ===\n");
    char str4[] = "Programming";
    printf("String: \"%s\"\n", str4);
    result = firstRepeatedCharIgnoreCase(str4);
    if (result != '\0') {
        printf("First repeated character (ignore case): '%c'\n", result);
    } else {
        printf("No repeated character\n");
    }
    
    // Test Case 5
    printf("\n=== Test Case 5 ===\n");
    char str5[] = "aabbcc";
    printf("String: \"%s\"\n", str5);
    result = firstRepeatedChar(str5);
    if (result != '\0') {
        printf("First repeated character: '%c'\n", result);
    } else {
        printf("No repeated character\n");
    }
    firstRepeatedWithIndex(str5);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 72: First Repeated Character ===
 * 
 * String: "geeksforgeeks"
 * First repeated character: 'g'
 * First repeated character: 'g' at index 0
 * 
 * === Test Case 2 ===
 * String: "hello"
 * First repeated character: 'l'
 * First repeated character: 'l' at index 2
 * 
 * === Test Case 3 ===
 * String: "abcdef"
 * No repeated character
 * No repeated character found
 * 
 * === Test Case 4 (Case Insensitive) ===
 * String: "Programming"
 * First repeated character (ignore case): 'r'
 * 
 * === Test Case 5 ===
 * String: "aabbcc"
 * First repeated character: 'a'
 * First repeated character: 'a' at index 0
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - two passes through string
 * - Space Complexity: O(1) - fixed size array (256 chars)
 * 
 * Key Points:
 * 1. Use hash table to count character occurrences
 * 2. Second pass finds first character with count > 1
 * 3. Can handle case-sensitive and case-insensitive
 * 4. Alternative: traverse from right to left for optimization
 */
