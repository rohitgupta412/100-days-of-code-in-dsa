#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node.
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to create a new node dynamically
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to build a linked list from user input
struct ListNode* buildList(int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct ListNode* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy head node to simplify the merging process
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part of the non-empty list
    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }

    return dummy.next;
}

// Function to print the linked list elements
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the memory used by the linked list (good practice)
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m;
    struct ListNode* head1 = NULL;
    struct ListNode* head2 = NULL;
    struct ListNode* mergedHead = NULL;

    // Input for first list
    if (scanf("%d", &n) == 1 && n > 0) {
        head1 = buildList(n);
    }

    // Input for second list
    if (scanf("%d", &m) == 1 && m > 0) {
        head2 = buildList(m);
    }

    // Merge the two lists
    mergedHead = mergeTwoLists(head1, head2);

    // Print the merged list
    printList(mergedHead);
    
    // Free allocated memory
    freeList(mergedHead);

    return 0;
}
