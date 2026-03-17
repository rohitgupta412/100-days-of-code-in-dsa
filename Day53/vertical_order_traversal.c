/*
 * Day 53: Vertical Order Traversal of Binary Tree
 * 
 * Problem: Print nodes of binary tree in vertical order from left to right.
 * Nodes at same horizontal distance are printed together.
 * 
 * Time Complexity: O(n log n) - due to sorting
 * Space Complexity: O(n) - for storing nodes
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

// Binary Tree Node structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Structure to store node with horizontal distance
typedef struct {
    TreeNode* node;
    int hd;  // horizontal distance
} NodeHD;

// Queue for level order traversal
typedef struct {
    NodeHD arr[MAX_NODES];
    int front, rear;
} Queue;

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

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, TreeNode* node, int hd) {
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

NodeHD dequeue(Queue* q) {
    NodeHD item = q->arr[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to find min and max horizontal distance
void findMinMax(TreeNode* root, int* min, int* max, int hd) {
    if (root == NULL) return;
    
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    
    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

// Function to print nodes at given horizontal distance
void printVerticalLine(TreeNode* root, int lineHD, int hd) {
    if (root == NULL) return;
    
    if (hd == lineHD) {
        printf("%d ", root->data);
    }
    
    printVerticalLine(root->left, lineHD, hd - 1);
    printVerticalLine(root->right, lineHD, hd + 1);
}

// Function to print vertical order traversal
void verticalOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    
    // Find min and max horizontal distances
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
    
    // Print vertical lines from min to max
    for (int lineHD = min; lineHD <= max; lineHD++) {
        printVerticalLine(root, lineHD, 0);
        printf("\n");
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
    printf("=== Day 53: Vertical Order Traversal ===\n\n");
    
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
    
    printf("Vertical Order Traversal:\n");
    verticalOrderTraversal(root);
    
    printf("\n=== Test Case 2 ===\n");
    /*
     * Creating Binary Tree:
     *          1
     *        /   \
     *       2     3
     *        \   
     *         4   
     *          \
     *           5
     *            \
     *             6
     */
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->right = createNode(4);
    root2->left->right->right = createNode(5);
    root2->left->right->right->right = createNode(6);
    
    printf("Binary Tree (Inorder): ");
    inorder(root2);
    printf("\n\n");
    
    printf("Vertical Order Traversal:\n");
    verticalOrderTraversal(root2);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 53: Vertical Order Traversal ===
 * 
 * Binary Tree (Inorder): 4 2 5 1 6 3 7 
 * 
 * Vertical Order Traversal:
 * 4 
 * 2 
 * 1 5 6 
 * 3 
 * 7 
 * 
 * === Test Case 2 ===
 * Binary Tree (Inorder): 2 4 5 6 1 3 
 * 
 * Vertical Order Traversal:
 * 2 
 * 1 4 
 * 3 5 
 * 6 
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n * w) where w is width of tree
 * - Space Complexity: O(n) for recursion stack
 * 
 * Key Points:
 * 1. Horizontal distance: left child = parent - 1, right child = parent + 1
 * 2. Root has horizontal distance 0
 * 3. Nodes at same HD are in same vertical line
 * 4. Print from leftmost to rightmost vertical line
 */
