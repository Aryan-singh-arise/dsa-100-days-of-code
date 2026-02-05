/* 
Question: Delete an Element from an Array (C)

Problem Statement:
Write a C program to delete an element from a given 1-based position pos in an array of n integers.
After deletion, shift the remaining elements to the left.

Input Format:

Enter number of elements in the array

Enter the array elements

Enter the position (1-based) to delete

Output Format:

Display the updated array after deletion.
*/

#include <stdio.h>

int main() {
    int n, pos;
    int arr[100];

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Updated array after deletion:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
