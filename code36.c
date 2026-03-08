#include <stdio.h>

int main() {
    int n, m;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    // Perform dequeue operations
    front = (front + m) % n;

    // Print elements from front to rear in circular manner
    int count = 0;
    int i = front;

    while(count < n) {
        printf("%d ", arr[i]);
        i = (i + 1) % n;
        count++;
    }

    return 0;
}