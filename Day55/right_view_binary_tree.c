/*
 * Day 55: Right View of Binary Tree
 * 
 * Problem: Print the right view of binary tree (rightmost node at each level)
 * 
 * Time Complexity: O(n) - where n is number of nodes
 * Space Complexity: O(h) - where h is height (recursion stack)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Binary Tree Node structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Global variable to track max level visited
int maxLevel = -1;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print right view using recursion
void rightViewUtil(TreeNode* root, int level) {
    if (root == NULL) return;
    
    // If this is the first node of its level
    if (maxLevel < level) {
        printf("%d ", root->data);
        maxLevel = level;
    }
    
    // Recur for right subtree first, then left
    rightViewUtil(root->right, level + 1);
    rightViewUtil(root->left, level + 1);
}

// Wrapper function for right view
void rightView(TreeNode* root) {
    maxLevel = -1;  // Reset for each call
    rightViewUtil(root, 0);
}

// Queue structure for level order approach
typedef struct {
    TreeNode* arr[MAX_SIZE];
    int front, rear;
} Queue;

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

// Function to print right view using level order traversal
void rightViewLevelOrder(TreeNode* root) {
    if (root == NULL) return;
    
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    
    while (!isQueueEmpty(&q)) {
        int levelSize = queueSize(&q);
        
        // Process all nodes at current level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = dequeue(&q);
            
            // Print the last node of each level
            if (i == levelSize - 1) {
                printf("%d ", current->data);
            }
            
            // Add children to queue
            if (current->left) enqueue(&q, current->left);
            if (current->right) enqueue(&q, current->right);
        }
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
    printf("=== Day 55: Right View of Binary Tree ===\n\n");
    
    /*
     * Creating Binary Tree:
     *          1
     *        /   \
     *       2     3
     *      / \     \
     *     4   5     6
     *              /
     *             7
     */
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);
    root->right->right->left = createNode(7);
    
    printf("Binary Tree (Inorder): ");
    inorder(root);
    printf("\n\n");
    
    printf("Right View (Recursive): ");
    rightView(root);
    printf("\n");
    
    printf("Right View (Level Order): ");
    rightViewLevelOrder(root);
    printf("\n");
    
    printf("\n=== Test Case 2 ===\n");
    /*
     * Creating Binary Tree:
     *          1
     *        /   
     *       2     
     *        \     
     *         3     
     *          \
     *           4
     */
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->left->right = createNode(3);
    root2->left->right->right = createNode(4);
    
    printf("Binary Tree (Inorder): ");
    inorder(root2);
    printf("\n\n");
    
    printf("Right View (Recursive): ");
    rightView(root2);
    printf("\n");
    
    printf("Right View (Level Order): ");
    rightViewLevelOrder(root2);
    printf("\n");
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 55: Right View of Binary Tree ===
 * 
 * Binary Tree (Inorder): 4 2 5 1 3 7 6 
 * 
 * Right View (Recursive): 1 3 6 7 
 * Right View (Level Order): 1 3 6 7 
 * 
 * === Test Case 2 ===
 * Binary Tree (Inorder): 2 3 4 1 
 * 
 * Right View (Recursive): 1 2 3 4 
 * Right View (Level Order): 1 2 3 4 
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - visits each node once
 * - Space Complexity: O(h) for recursive, O(w) for level order
 *   where h = height, w = max width
 * 
 * Key Points:
 * 1. Right view shows rightmost node at each level
 * 2. Two approaches: recursive (DFS) and level order (BFS)
 * 3. Recursive visits right subtree first
 * 4. Level order prints last node of each level
 */
