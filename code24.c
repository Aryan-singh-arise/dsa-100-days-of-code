#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    
    // If list is empty
    if (head == NULL)
        return NULL;

    struct Node *temp = head, *prev = NULL;

    // If head itself holds the key
    if (temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse the list
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key not found
    if (temp == NULL)
        return head;

    // Remove node
    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int n, key;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Creating linked list
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    head = deleteFirstOccurrence(head, key);

    // Print updated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}