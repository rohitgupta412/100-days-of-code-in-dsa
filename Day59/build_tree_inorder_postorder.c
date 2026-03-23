/*
 * Day 59: Build Binary Tree from Inorder and Postorder Traversal
 * 
 * Problem: Construct binary tree from inorder and postorder traversal arrays
 * 
 * Time Complexity: O(n) - where n is number of nodes
 * Space Complexity: O(n) - for recursion stack and tree
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

// Helper function to find index of element in inorder array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Recursive function to build tree
TreeNode* buildTreeUtil(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }
    
    // Pick current node from postorder using postIndex (from end)
    TreeNode* node = createNode(postorder[*postIndex]);
    (*postIndex)--;
    
    // If this node has no children, return
    if (inStart == inEnd) {
        return node;
    }
    
    // Find index of this node in inorder traversal
    int inIndex = findIndex(inorder, inStart, inEnd, node->data);
    
    // Build right subtree first (postorder is LRN, so we go RLN in reverse)
    node->right = buildTreeUtil(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeUtil(inorder, postorder, inStart, inIndex - 1, postIndex);
    
    return node;
}

// Main function to build tree
TreeNode* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;  // Start from last element
    return buildTreeUtil(inorder, postorder, 0, n - 1, &postIndex);
}

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// Helper function to print preorder traversal
void printPreorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

// Helper function to print postorder traversal
void printPostorder(TreeNode* root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function
int main() {
    printf("=== Day 59: Build Tree from Inorder and Postorder ===\n\n");
    
    /*
     * Example Tree:
     *          1
     *        /   \
     *       2     3
     *      / \   / \
     *     4   5 6   7
     */
    
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    
    printf("Given Traversals:\n");
    printf("Inorder:   ");
    for (int i = 0; i < n; i++) printf("%d ", inorder[i]);
    printf("\n");
    printf("Postorder: ");
    for (int i = 0; i < n; i++) printf("%d ", postorder[i]);
    printf("\n\n");
    
    TreeNode* root = buildTree(inorder, postorder, n);
    
    printf("Constructed Tree Traversals:\n");
    printf("Inorder:   ");
    printInorder(root);
    printf("\n");
    printf("Preorder:  ");
    printPreorder(root);
    printf("\n");
    printf("Postorder: ");
    printPostorder(root);
    printf("\n");
    
    printf("\n=== Test Case 2 ===\n");
    int inorder2[] = {2, 1, 3};
    int postorder2[] = {2, 3, 1};
    int n2 = sizeof(inorder2) / sizeof(inorder2[0]);
    
    printf("Given Traversals:\n");
    printf("Inorder:   ");
    for (int i = 0; i < n2; i++) printf("%d ", inorder2[i]);
    printf("\n");
    printf("Postorder: ");
    for (int i = 0; i < n2; i++) printf("%d ", postorder2[i]);
    printf("\n\n");
    
    TreeNode* root2 = buildTree(inorder2, postorder2, n2);
    
    printf("Constructed Tree Traversals:\n");
    printf("Inorder:   ");
    printInorder(root2);
    printf("\n");
    printf("Postorder: ");
    printPostorder(root2);
    printf("\n");
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 59: Build Tree from Inorder and Postorder ===
 * 
 * Given Traversals:
 * Inorder:   4 2 5 1 6 3 7 
 * Postorder: 4 5 2 6 7 3 1 
 * 
 * Constructed Tree Traversals:
 * Inorder:   4 2 5 1 6 3 7 
 * Preorder:  1 2 4 5 3 6 7 
 * Postorder: 4 5 2 6 7 3 1 
 * 
 * === Test Case 2 ===
 * Given Traversals:
 * Inorder:   2 1 3 
 * Postorder: 2 3 1 
 * 
 * Constructed Tree Traversals:
 * Inorder:   2 1 3 
 * Postorder: 2 3 1 
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(n²) - due to findIndex in each call
 *   Can be optimized to O(n) using hashmap
 * - Space Complexity: O(n) - recursion stack
 * 
 * Key Points:
 * 1. Postorder: Root is last element
 * 2. Inorder: Elements left of root are in left subtree
 * 3. Elements right of root are in right subtree
 * 4. Build right subtree first (reverse of postorder)
 */
