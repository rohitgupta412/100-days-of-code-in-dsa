/*
 * Day 95: Bucket Sort
 * 
 * Problem: Sort array using bucket sort algorithm
 * Works well for uniformly distributed data
 * 
 * Time Complexity: O(n + k) average, O(n²) worst
 * Space Complexity: O(n + k)
 */

#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

typedef struct Node {
    float data;
    struct Node* next;
} Node;

void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void bucketSort(float arr[], int n) {
    Node* buckets[BUCKET_COUNT] = {NULL};
    
    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * BUCKET_COUNT);
        if (bucketIndex >= BUCKET_COUNT) bucketIndex = BUCKET_COUNT - 1;
        insertSorted(&buckets[bucketIndex], arr[i]);
    }
    
    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    printf("=== Day 95: Bucket Sort ===\n\n");
    
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");
    
    bucketSort(arr, n);
    
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.4f ", arr[i]);
    }
    printf("\n");
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
