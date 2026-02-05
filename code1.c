/*Question: Reverse an Array In-Place

Problem Statement:
Given an array of n integers, write a C program to reverse the array in-place using the two-pointer approach.

Input:

First line contains an integer n — the number of elements in the array.

Second line contains n space-separated integers — the elements of the array.

Output:

Print the reversed array in a single line, with elements separated by spaces.
*/



#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }

    int left = 0, right = n - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
