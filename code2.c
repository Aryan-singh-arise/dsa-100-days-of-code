/*Question: Insert an Element in an Array (C)

Problem Statement:
Write a C program to insert an element x at a given 1-based position pos in an array of n integers.
Shift the existing elements to the right to make space for the new element.

Input Format:

First line: Integer n (number of elements in the array)

Second line: n space-separated integers (array elements)

Third line: Integer pos (1-based position where element is to be inserted)

Fourth line: Integer x (element to insert)

Output Format:

Print the updated array (n+1 elements) in a single line, space-separated
*/

#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    printf("Updated array is:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
