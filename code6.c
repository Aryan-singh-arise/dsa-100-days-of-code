#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Edge case: if array has 0 or 1 element
    if (n == 0) {
        return 0;
    }

    int k = 1; // index for unique elements

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    printf("Unique elements are:\n");
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
