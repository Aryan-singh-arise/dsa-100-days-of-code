#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[1000];

        // Store level elements
        for (int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];
            level[i] = temp->data;

            if (temp->left)  queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }

        // Print according to direction
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight; // flip direction
    }
}