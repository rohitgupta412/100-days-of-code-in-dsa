#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Function to count the number of nodes in a linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Main function to drive the program
int main() {
    struct Node* head = NULL;
    int n, value;

    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    // Read the elements and insert into the linked list
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) != 1) return 1;
        insertEnd(&head, value);
    }

    // Count the nodes
    int count = countNodes(head);

    // Print the result
    printf("Total nodes: %d\n", count);

    // Free memory (optional, but good practice for completeness)
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
