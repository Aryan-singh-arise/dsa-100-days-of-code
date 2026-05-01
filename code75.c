#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define OFFSET 1000000  // to handle negative sums safely

int maxLen(int arr[], int n) {
    int *hash = (int*)malloc(sizeof(int) * (2 * OFFSET + 1));
    
    // initialize with -2 (means not seen)
    for(int i = 0; i <= 2 * OFFSET; i++) {
        hash[i] = -2;
    }

    int sum = 0, max_len = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            max_len = i + 1;
        }

        if(hash[sum + OFFSET] != -2) {
            int prev_index = hash[sum + OFFSET];
            int len = i - prev_index;
            if(len > max_len)
                max_len = len;
        } else {
            hash[sum + OFFSET] = i; // store first occurrence
        }
    }

    free(hash);
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));
    return 0;
}