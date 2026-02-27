#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Get length
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;

    // First List
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = createNode(val);

        if (head1 == NULL) {
            head1 = tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;

    // Second List
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);

        // Check if value exists in first list
        struct Node* temp = head1;
        struct Node* match = NULL;

        while (temp != NULL) {
            if (temp->data == val) {
                match = temp;
                break;
            }
            temp = temp->next;
        }

        if (match != NULL) {
            if (head2 == NULL)
                head2 = tail2 = match;
            else {
                tail2->next = match;
                tail2 = match;
            }
            break; // remaining nodes already connected
        } else {
            struct Node* newNode = createNode(val);

            if (head2 == NULL) {
                head2 = tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}