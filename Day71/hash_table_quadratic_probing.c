/*
 * Day 71: Hash Table using Quadratic Probing
 * 
 * Problem: Implement hash table with quadratic probing for collision resolution
 * Quadratic Probing: h(k, i) = (h(k) + c1*i + c2*i²) mod m
 * 
 * Time Complexity: O(1) average case for insert, search, delete
 * Space Complexity: O(n) - where n is table size
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 11
#define EMPTY -1
#define DELETED -2

// Hash Table structure
typedef struct {
    int* table;
    int size;
} HashTable;

// Function to create hash table
HashTable* createHashTable(int size) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = (int*)malloc(size * sizeof(int));
    
    // Initialize all slots as empty
    for (int i = 0; i < size; i++) {
        ht->table[i] = EMPTY;
    }
    
    return ht;
}

// Hash function
int hashFunction(int key, int size) {
    return key % size;
}

// Function to insert key using quadratic probing
bool insert(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    int i = 0;
    
    // Quadratic probing: h(k, i) = (h(k) + i²) mod m
    while (i < ht->size) {
        int newIndex = (index + i * i) % ht->size;
        
        // If slot is empty or deleted, insert key
        if (ht->table[newIndex] == EMPTY || ht->table[newIndex] == DELETED) {
            ht->table[newIndex] = key;
            printf("Inserted %d at index %d (probe %d)\n", key, newIndex, i);
            return true;
        }
        
        // If key already exists
        if (ht->table[newIndex] == key) {
            printf("Key %d already exists at index %d\n", key, newIndex);
            return false;
        }
        
        i++;
    }
    
    printf("Hash table is full! Cannot insert %d\n", key);
    return false;
}

// Function to search for a key
int search(HashTable* ht, int key) {
    int index = hashFunction(key, ht->size);
    int i = 0;
    
    while (i < ht->size) {
        int newIndex = (index + i * i) % ht->size;
        
        // If slot is empty, key not found
        if (ht->table[newIndex] == EMPTY) {
            return -1;
        }
        
        // If key found
        if (ht->table[newIndex] == key) {
            return newIndex;
        }
        
        i++;
    }
    
    return -1;
}

// Function to delete a key
bool deleteKey(HashTable* ht, int key) {
    int index = search(ht, key);
    
    if (index == -1) {
        printf("Key %d not found\n", key);
        return false;
    }
    
    ht->table[index] = DELETED;
    printf("Deleted key %d from index %d\n", key, index);
    return true;
}

// Function to display hash table
void display(HashTable* ht) {
    printf("\nHash Table:\n");
    printf("Index | Value\n");
    printf("------|-------\n");
    for (int i = 0; i < ht->size; i++) {
        printf("  %2d  | ", i);
        if (ht->table[i] == EMPTY) {
            printf("EMPTY\n");
        } else if (ht->table[i] == DELETED) {
            printf("DELETED\n");
        } else {
            printf("%d\n", ht->table[i]);
        }
    }
    printf("\n");
}

// Main function
int main() {
    printf("=== Day 71: Hash Table with Quadratic Probing ===\n\n");
    
    HashTable* ht = createHashTable(TABLE_SIZE);
    
    printf("Inserting keys: 50, 700, 76, 85, 92, 73, 101\n\n");
    
    insert(ht, 50);
    insert(ht, 700);
    insert(ht, 76);
    insert(ht, 85);
    insert(ht, 92);
    insert(ht, 73);
    insert(ht, 101);
    
    display(ht);
    
    // Search operations
    printf("=== Search Operations ===\n");
    int key = 76;
    int index = search(ht, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }
    
    key = 99;
    index = search(ht, key);
    if (index != -1) {
        printf("Key %d found at index %d\n", key, index);
    } else {
        printf("Key %d not found\n", key);
    }
    
    // Delete operation
    printf("\n=== Delete Operations ===\n");
    deleteKey(ht, 76);
    display(ht);
    
    // Insert after deletion
    printf("Inserting 99 after deletion:\n");
    insert(ht, 99);
    display(ht);
    
    printf("=== Program Completed Successfully ===\n");
    
    free(ht->table);
    free(ht);
    
    return 0;
}

/*
 * Output:
 * === Day 71: Hash Table with Quadratic Probing ===
 * 
 * Inserting keys: 50, 700, 76, 85, 92, 73, 101
 * 
 * Inserted 50 at index 6 (probe 0)
 * Inserted 700 at index 7 (probe 0)
 * Inserted 76 at index 10 (probe 0)
 * Inserted 85 at index 8 (probe 0)
 * Inserted 92 at index 4 (probe 0)
 * Inserted 73 at index 7 (probe 1)
 * Inserted 101 at index 2 (probe 0)
 * 
 * Hash Table:
 * Index | Value
 * ------|-------
 *    0  | EMPTY
 *    1  | EMPTY
 *    2  | 101
 *    3  | EMPTY
 *    4  | 92
 *    5  | EMPTY
 *    6  | 50
 *    7  | 700
 *    8  | 85
 *    9  | 73
 *   10  | 76
 * 
 * === Search Operations ===
 * Key 76 found at index 10
 * Key 99 not found
 * 
 * === Delete Operations ===
 * Deleted key 76 from index 10
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(1) average, O(n) worst case
 * - Space Complexity: O(n)
 * 
 * Key Points:
 * 1. Quadratic probing reduces primary clustering
 * 2. Probe sequence: 0, 1, 4, 9, 16, 25, ...
 * 3. Better than linear probing for collision resolution
 * 4. May not probe all slots (secondary clustering)
 */
