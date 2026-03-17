/*Problem Statement:
Find the height (maximum depth) of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print the height of the tree

Example:
Input:
7
1 2 3 4 5 -1 -1

Output:
3*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node Structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue for tree construction
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue functions
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[q->rear++] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Height function
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int val;
    scanf("%d", &val);

    struct Node* root = NULL;

    if (val == -1) {
        printf("0\n");
        return 0;
    }

    root = createNode(val);

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int count = 1;

    while (count < n && !isEmpty(&q)) {
        struct Node* current = dequeue(&q);

        // Left child
        if (count < n) {
            scanf("%d", &val);
            count++;
            if (val != -1) {
                current->left = createNode(val);
                enqueue(&q, current->left);
            }
        }

        // Right child
        if (count < n) {
            scanf("%d", &val);
            count++;
            if (val != -1) {
                current->right = createNode(val);
                enqueue(&q, current->right);
            }
        }
    }

    printf("%d\n", height(root));

    return 0;
}