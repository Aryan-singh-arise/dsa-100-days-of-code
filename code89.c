#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) {
            return 0; // single book exceeds limit
        }

        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];

            if (students > m) {
                return 0;
            }
        } else {
            pagesSum += arr[i];
        }
    }

    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;   // minimum possible answer
    int high = sum;  // maximum possible answer
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;       // valid allocation
            high = mid - 1;  // try smaller max
        } else {
            low = mid + 1;   // increase limit
        }
    }

    printf("%d\n", ans);

    return 0;
}