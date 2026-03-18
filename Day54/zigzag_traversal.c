/*
 * Day 54: Zigzag (Spiral) Level Order Traversal
 * 
 * Problem: Print binary tree in zigzag order (left to right, then right to left)
 * 
 * Time Complexity: O(n) - where n is number of nodes
 * Space Complexity: O(n) - for queue storage
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Binary Tree Node structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Queue structure
typedef struct {
    TreeNode* arr[MAX_SIZE];
    int front, rear;
} Queue;

// Stack structure for reversing
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue operations
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, TreeNode* node) {
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear] = node;
}

TreeNode* dequeue(Queue* q) {
    TreeNode* item = q->arr[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

int queueSize(Queue* q) {
    if (q->front == -1) return 0;
    return q->rear - q->front + 1;
}

// Stack operations
void initStack(Stack* s) {
    s->top = -1;
}

int isStackEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int data) {
    s->arr[++s->top] = data;
}

int pop(Stack* s) {
    return s->arr[s->top--];
}

// Function to perform zigzag level order traversal
void zigzagTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    
    bool leftToRight = true;
    
    while (!isQueueEmpty(&q)) {
        int levelSize = queueSize(&q);
        Stack s;
        initStack(&s);
        
        // Process all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = dequeue(&q);
            
            if (leftToRight) {
                printf("%d ", current->data);
            } else {
                push(&s, current->data);
            }
            
            // Add children to queue
            if (current->left) enqueue(&q, current->left);
            if (current->right) enqueue(&q, current->right);
        }
        
        // Print from stack if right to left
        while (!isStackEmpty(&s)) {
            printf("%d ", pop(&s));
        }
        
        printf("\n");
        leftToRight = !leftToRight;  // Toggle direction
    }
}

// Helper function to print inorder traversal
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    printf("=== Day 54: Zigzag Level Order Traversal ===\n\n");
    
    /*
     * Creating Binary Tree:
     *          1
     *        /   \
     *       2     3
     *      / \   / \
     *     4   5 6   7
     */
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    printf("Binary Tree (Inorder): ");
    inorder(root);
    printf("\n\n");
    
    printf("Zigzag Traversal:\n");
    zigzagTraversal(root);
    
    printf("\n=== Test Case 2 ===\n");
    /*
     * Creating Binary Tree:
     *          1
     *        /   \
     *       2     3
     *      /     / \
     *     4     5   6
     *    /         / \
     *   7         8   9
     */
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->right->left = createNode(5);
    root2->right->right = createNode(6);
    root2->left->left->left = createNode(7);
    root2->right->right->left = createNode(8);
    root2->right->right->right = createNode(9);
    
    printf("Binary Tree (Inorder): ");
    inorder(root2);
    printf("\n\n");
    
    printf("Zigzag Traversal:\n");
    zigzagTraversal(root2);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 54: Zigzag Level Order Traversal ===
 * 
 * Binary Tree (Inorder): 4 2 5 1 6 3 7 
 * 
 * Zigzag Traversal:
 * 1 
 * 3 2 
 * 4 5 6 7 
 * 
 * === Test Case 2 ===
 * Binary Tree (Inorder): 7 4 2 1 5 3 8 6 9 
 * 
 * Zigzag Traversal:
 * 1 
 * 3 2 
 * 4 5 6 
 * 9 8 7 
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - visits each node once
 * - Space Complexity: O(n) - queue and stack storage
 * 
 * Key Points:
 * 1. Level 0: left to right
 * 2. Level 1: right to left
 * 3. Level 2: left to right (alternates)
 * 4. Uses queue for level order and stack for reversing
 */
