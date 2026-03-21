/*
 * Day 57: Mirror/Invert Binary Tree
 * 
 * Problem: Convert a binary tree into its mirror image
 * 
 * Time Complexity: O(n) - where n is number of nodes
 * Space Complexity: O(h) - where h is height (recursion stack)
 */

#include <stdio.h>
#include <stdlib.h>

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

// Function to mirror/invert the binary tree
TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    
    // Recursively mirror left and right subtrees
    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);
    
    // Swap left and right children
    root->left = right;
    root->right = left;
    
    return root;
}

// Helper function to print inorder traversal
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Helper function to print preorder traversal
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Main function
int main() {
    printf("=== Day 57: Mirror/Invert Binary Tree ===\n\n");
    
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
    
    printf("Original Tree:\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n\n");
    
    // Mirror the tree
    mirrorTree(root);
    
    printf("After Mirroring:\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    /*
     * After mirroring:
     *          1
     *        /   \
     *       3     2
     *      / \   / \
     *     7   6 5   4
     */
    
    printf("\n=== Test Case 2 ===\n");
    TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    
    printf("Original Tree:\n");
    printf("Inorder: ");
    inorder(root2);
    printf("\n");
    
    mirrorTree(root2);
    
    printf("After Mirroring:\n");
    printf("Inorder: ");
    inorder(root2);
    printf("\n");
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 57: Mirror/Invert Binary Tree ===
 * 
 * Original Tree:
 * Inorder: 4 2 5 1 6 3 7 
 * Preorder: 1 2 4 5 3 6 7 
 * 
 * After Mirroring:
 * Inorder: 7 3 6 1 5 2 4 
 * Preorder: 1 3 7 6 2 5 4 
 * 
 * === Test Case 2 ===
 * Original Tree:
 * Inorder: 4 2 1 3 
 * After Mirroring:
 * Inorder: 3 1 2 4 
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - visits each node once
 * - Space Complexity: O(h) - recursion stack height
 * 
 * Key Points:
 * 1. Swap left and right children at each node
 * 2. Recursively mirror left and right subtrees
 * 3. Also known as "Invert Binary Tree"
 * 4. Famous LeetCode problem
 */
