#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Find LCA in BST
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If both smaller → go left
    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    // If both greater → go right
    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    // Split point → LCA
    return root;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* ans = LCA(root, n1, n2);

    if (ans)
        printf("%d", ans->data);

    return 0;
}