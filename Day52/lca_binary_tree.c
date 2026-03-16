/*
 * Day 52: Lowest Common Ancestor in Binary Tree
 * 
 * Problem: Find the lowest common ancestor (LCA) of two nodes in a binary tree.
 * LCA is the lowest node that has both nodes as descendants.
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

// Function to find LCA in Binary Tree
TreeNode* findLCA(TreeNode* root, int n1, int n2) {
    // Base case
    if (root == NULL) {
        return NULL;
    }
    
    // If either n1 or n2 matches with root's data, report the presence
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    
    // Look for keys in left and right subtrees
    TreeNode* leftLCA = findLCA(root->left, n1, n2);
    TreeNode* rightLCA = findLCA(root->right, n1, n2);
    
    // If both left and right are not NULL, root is LCA
    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }
    
    // Otherwise return non-NULL value
    return (leftLCA != NULL) ? leftLCA : rightLCA;
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
    printf("=== Day 52: Lowest Common Ancestor in Binary Tree ===\n\n");
    
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
    
    // Test Case 1: LCA of 4 and 5
    int n1 = 4, n2 = 5;
    TreeNode* lca = findLCA(root, n1, n2);
    printf("LCA of %d and %d: %d\n", n1, n2, lca ? lca->data : -1);
    
    // Test Case 2: LCA of 4 and 6
    n1 = 4; n2 = 6;
    lca = findLCA(root, n1, n2);
    printf("LCA of %d and %d: %d\n", n1, n2, lca ? lca->data : -1);
    
    // Test Case 3: LCA of 3 and 4
    n1 = 3; n2 = 4;
    lca = findLCA(root, n1, n2);
    printf("LCA of %d and %d: %d\n", n1, n2, lca ? lca->data : -1);
    
    // Test Case 4: LCA of 2 and 4
    n1 = 2; n2 = 4;
    lca = findLCA(root, n1, n2);
    printf("LCA of %d and %d: %d\n", n1, n2, lca ? lca->data : -1);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 52: Lowest Common Ancestor in Binary Tree ===
 * 
 * Binary Tree (Inorder): 4 2 5 1 6 3 7 
 * 
 * LCA of 4 and 5: 2
 * LCA of 4 and 6: 1
 * LCA of 3 and 4: 1
 * LCA of 2 and 4: 2
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n) - visits each node once
 * - Space Complexity: O(h) - recursion stack height
 * 
 * Key Points:
 * 1. Works for any binary tree (not just BST)
 * 2. Assumes both nodes exist in tree
 * 3. Single traversal solution
 * 4. Returns first common ancestor found
 */
