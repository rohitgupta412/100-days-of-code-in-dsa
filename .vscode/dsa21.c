#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to insert a new node at the end
void insert_at_end(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = new_node;
}

// Function to traverse and print the list
void print_list(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;
    int n, i, element;
    if (scanf("%d", &n) != 1) return 1;
    for (i = 0; i < n; i++) {
        if (scanf("%d", &element) == 1)
            insert_at_end(&head, element); //
    }
    print_list(head); //
    return 0;
}
