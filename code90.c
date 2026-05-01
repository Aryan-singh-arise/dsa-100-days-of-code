#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int timeSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) {
            return 0;
        }

        if (timeSum + arr[i] > maxTime) {
            painters++;
            timeSum = arr[i];

            if (painters > k) {
                return 0;
            }
        } else {
            timeSum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;   // minimum possible time
    int high = sum;  // maximum possible time
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;       // valid solution
            high = mid - 1;  // try smaller time
        } else {
            low = mid + 1;   // increase time
        }
    }

    printf("%d\n", ans);

    return 0;
}