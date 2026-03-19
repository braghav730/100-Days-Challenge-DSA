/*Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node in simple binary tree (level-wise for demo)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (root->left == NULL)
        root->left = insert(root->left, data);
    else if (root->right == NULL)
        root->right = insert(root->right, data);
    else
        root->left = insert(root->left, data);

    return root;
}

// Function to calculate height
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int n, val;
    struct Node* root = NULL;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("%d\n", height(root));

    return 0;
}