#include <stdio.h>
#include <stdlib.h>

// Node for linked list (used as bucket)
typedef struct Node {
    float data;
    struct Node* next;
} Node;

// Insert in sorted order (for each bucket)
void insertSorted(Node** head, float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    // insert at beginning or empty
    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data < value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // create n buckets
    Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n); // bucket index
        insertSorted(&buckets[index], arr[i]);
    }

    // concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = buckets[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }

    return 0;
}