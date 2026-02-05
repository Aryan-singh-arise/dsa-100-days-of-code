/*
📌 Question: Arrange Arrival Logs (Merge Two Sorted Arrays)

Problem Statement:
A system receives two separate logs of user arrival times from two different servers.
Each log is already sorted in ascending order.

Write a C program to merge both logs into a single chronological log while maintaining the sorted order.

Input Format (What the user enters):

Enter number of entries in server log 1

Enter the sorted arrival times from server log 1

Enter number of entries in server log 2

Enter the sorted arrival times from server log 2

Output Format:

Print all arrival times in chronological (sorted) order in a single line.
*/

#include <stdio.h>

int main() {
    int p, q;
    int a[100], b[100], c[200];
    int i = 0, j = 0, k = 0;

    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);

    printf("Enter %d sorted arrival times for server log 1:\n", p);
    for (i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);

    printf("Enter %d sorted arrival times for server log 2:\n", q);
    for (j = 0; j < q; j++) {
        scanf("%d", &b[j]);
    }

    i = 0;
    j = 0;

    // Merge the two sorted arrays
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    // Copy remaining elements
    while (i < p) {
        c[k++] = a[i++];
    }

    while (j < q) {
        c[k++] = b[j++];
    }

    printf("Merged arrival log:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}
