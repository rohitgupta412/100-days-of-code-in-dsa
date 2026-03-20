/*
 * Day 56: Check if Binary Tree is Symmetric
 * 
 * Problem: Check if a binary tree is mirror image of itself (symmetric)
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

// Helper function to check if two trees are mirror images
bool isMirror(TreeNode* left, TreeNode* right) {
    // Both NULL - symmetric
    if (left == NULL && right == NULL) {
        return true;
    }
    
    // One NULL, other not - not symmetric
    if (left == NULL || right == NULL) {
        return false;
    }
    
    // Check if data matches and subtrees are mirrors
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Function to check if tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
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
    printf("=== Day 56: Check Symmetric Binary Tree ===\n\n");
    
    /*
     * Creating Symmetric Tree:
     *          1
     *        /   \
     *       2     2
     *      / \   / \
     *     3   4 4   3
     */
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->left = createNode(4);
    root1->right->right = createNode(3);
    
    printf("Test Case 1 (Symmetric Tree):\n");
    printf("Tree (Inorder): ");
    inorder(root1);
    printf("\n");
    printf("Is Symmetric? %s\n", isSymmetric(root1) ? "Yes" : "No");
    
    printf("\n=== Test Case 2 (Not Symmetric) ===\n");
    /*
     * Creating Non-Symmetric Tree:
     *          1
     *        /   \
     *       2     2
     *        \     \
     *         3     3
     */
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->right = createNode(3);
    root2->right->right = createNode(3);
    
    printf("Tree (Inorder): ");
    inorder(root2);
    printf("\n");
    printf("Is Symmetric? %s\n", isSymmetric(root2) ? "Yes" : "No");
    
    printf("\n=== Test Case 3 (Single Node) ===\n");
    TreeNode* root3 = createNode(1);
    printf("Tree (Inorder): ");
    inorder(root3);
    printf("\n");
    printf("Is Symmetric? %s\n", isSymmetric(root3) ? "Yes" : "No");
    
    printf("\n=== Test Case 4 (Perfect Symmetric) ===\n");
    /*
     * Creating Perfect Symmetric Tree:
     *          1
     *        /   \
     *       2     2
     */
    TreeNode* root4 = createNode(1);
    root4->left = createNode(2);
    root4->right = createNode(2);
    
    printf("Tree (Inorder): ");
    inorder(root4);
    printf("\n");
    printf("Is Symmetric? %s\n", isSymmetric(root4) ? "Yes" : "No");
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 56: Check Symmetric Binary Tree ===
 * 
 * Test Case 1 (Symmetric Tree):
 * Tree (Inorder): 3 2 4 1 4 2 3 
 * Is Symmetric? Yes
 * 
 * === Test Case 2 (Not Symmetric) ===
 * Tree (Inorder): 2 3 1 2 3 
 * Is Symmetric? No
 * 
 * === Test Case 3 (Single Node) ===
 * Tree (Inorder): 1 
 * Is Symmetric? Yes
 * 
 * === Test Case 4 (Perfect Symmetric) ===
 * Tree (Inorder): 2 1 2 
 * Is Symmetric? Yes
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - visits each node once
 * - Space Complexity: O(h) - recursion stack height
 * 
 * Key Points:
 * 1. Tree is symmetric if left and right subtrees are mirrors
 * 2. Mirror means: left.left = right.right and left.right = right.left
 * 3. Empty tree is symmetric
 * 4. Single node tree is symmetric
 */
