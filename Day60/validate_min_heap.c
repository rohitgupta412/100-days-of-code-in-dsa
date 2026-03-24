/*
 * Day 60: Validate Min-Heap
 * 
 * Problem: Check if a given binary tree is a valid min-heap
 * Min-Heap properties:
 * 1. Complete binary tree
 * 2. Parent <= Children
 * 
 * Time Complexity: O(n) - where n is number of nodes
 * Space Complexity: O(h) - where h is height (recursion stack)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Tree Node structure
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to count total nodes in tree
int countNodes(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to check if tree is complete binary tree
bool isCompleteTree(TreeNode* root, int index, int totalNodes) {
    if (root == NULL) return true;
    
    // If index is >= total nodes, not complete
    if (index >= totalNodes) return false;
    
    // Check recursively for left and right subtrees
    return isCompleteTree(root->left, 2 * index + 1, totalNodes) &&
           isCompleteTree(root->right, 2 * index + 2, totalNodes);
}

// Function to check heap property (parent <= children)
bool isHeapProperty(TreeNode* root) {
    if (root == NULL) return true;
    
    // Check left child
    if (root->left != NULL) {
        if (root->data > root->left->data) return false;
        if (!isHeapProperty(root->left)) return false;
    }
    
    // Check right child
    if (root->right != NULL) {
        if (root->data > root->right->data) return false;
        if (!isHeapProperty(root->right)) return false;
    }
    
    return true;
}

// Main function to validate min-heap
bool isMinHeap(TreeNode* root) {
    if (root == NULL) return true;
    
    int totalNodes = countNodes(root);
    
    // Check both conditions: complete tree and heap property
    return isCompleteTree(root, 0, totalNodes) && isHeapProperty(root);
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
    printf("=== Day 60: Validate Min-Heap ===\n\n");
    
    /*
     * Creating Valid Min-Heap:
     *          1
     *        /   \
     *       2     3
     *      / \   /
     *     4   5 6
     */
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);
    root1->right->left = createNode(6);
    
    printf("Test Case 1 (Valid Min-Heap):\n");
    printf("Tree (Inorder): ");
    inorder(root1);
    printf("\n");
    printf("Is Min-Heap? %s\n", isMinHeap(root1) ? "Yes" : "No");
    
    printf("\n=== Test Case 2 (Invalid - Not Heap Property) ===\n");
    /*
     * Creating Invalid Heap (parent > child):
     *          5
     *        /   \
     *       2     3
     *      / \   
     *     4   1
     */
    TreeNode* root2 = createNode(5);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(1);
    
    printf("Tree (Inorder): ");
    inorder(root2);
    printf("\n");
    printf("Is Min-Heap? %s\n", isMinHeap(root2) ? "Yes" : "No");
    
    printf("\n=== Test Case 3 (Invalid - Not Complete Tree) ===\n");
    /*
     * Creating Incomplete Tree:
     *          1
     *        /   \
     *       2     3
     *            /
     *           4
     */
    TreeNode* root3 = createNode(1);
    root3->left = createNode(2);
    root3->right = createNode(3);
    root3->right->left = createNode(4);
    
    printf("Tree (Inorder): ");
    inorder(root3);
    printf("\n");
    printf("Is Min-Heap? %s\n", isMinHeap(root3) ? "Yes" : "No");
    
    printf("\n=== Test Case 4 (Single Node) ===\n");
    TreeNode* root4 = createNode(1);
    printf("Tree (Inorder): ");
    inorder(root4);
    printf("\n");
    printf("Is Min-Heap? %s\n", isMinHeap(root4) ? "Yes" : "No");
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 60: Validate Min-Heap ===
 * 
 * Test Case 1 (Valid Min-Heap):
 * Tree (Inorder): 4 2 5 1 6 3 
 * Is Min-Heap? Yes
 * 
 * === Test Case 2 (Invalid - Not Heap Property) ===
 * Tree (Inorder): 4 2 1 5 3 
 * Is Min-Heap? No
 * 
 * === Test Case 3 (Invalid - Not Complete Tree) ===
 * Tree (Inorder): 2 1 4 3 
 * Is Min-Heap? No
 * 
 * === Test Case 4 (Single Node) ===
 * Tree (Inorder): 1 
 * Is Min-Heap? Yes
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - visits each node once
 * - Space Complexity: O(h) - recursion stack height
 * 
 * Key Points:
 * 1. Min-Heap must be complete binary tree
 * 2. Parent value <= both children values
 * 3. Check both properties independently
 * 4. Empty tree and single node are valid heaps
 */
