#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n) {
    int max = findMax(arr, n);

    // frequency array
    int *count = (int *)calloc(max + 1, sizeof(int));

    // count frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // output array
    int *output = (int *)malloc(n * sizeof(int));

    // build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}