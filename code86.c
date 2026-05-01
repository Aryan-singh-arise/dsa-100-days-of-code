#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == n) {
            ans = mid;
            break;
        }
        else if (square < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}