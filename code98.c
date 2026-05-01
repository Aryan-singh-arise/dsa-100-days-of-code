#include <stdio.h>
#include <stdlib.h>

// structure for interval
typedef struct {
    int start;
    int end;
} Interval;

// sort by start time
int cmp(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // sort intervals
    qsort(arr, n, sizeof(Interval), cmp);

    // result array
    Interval result[n];
    int idx = 0;

    // initialize first interval
    result[idx++] = arr[0];

    for (int i = 1; i < n; i++) {
        // check overlap
        if (arr[i].start <= result[idx - 1].end) {
            // merge
            if (arr[i].end > result[idx - 1].end) {
                result[idx - 1].end = arr[i].end;
            }
        } else {
            // no overlap
            result[idx++] = arr[i];
        }
    }

    // print merged intervals
    for (int i = 0; i < idx; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}