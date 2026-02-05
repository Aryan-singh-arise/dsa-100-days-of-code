/*
ser Side):

Enter the size of the array

Enter the array elements

Enter the key to search

Output Format:

Line 1: Found at index i OR Not Found

Line 2: Comparisons = c

⚠️ Indexing is 0-based (same as your example).

*/

#include <stdio.h>

int main() {
    int n, key;
    int arr[100];
    int comparisons = 0;
    int found = -1;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    // Linear Search
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}
