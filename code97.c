#include <stdio.h>
#include <stdlib.h>

// structure for intervals
typedef struct {
    int start;
    int end;
} Interval;

// compare function for sorting by start time
int cmpStart(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

// min-heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[smallest], &heap[index]);
            index = smallest;
        } else break;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int top(int heap[]) {
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // sort intervals by start time
    qsort(arr, n, sizeof(Interval), cmpStart);

    // min heap for end times
    int heap[n];
    int heapSize = 0;

    // process first meeting
    push(heap, &heapSize, arr[0].end);

    // process remaining meetings
    for (int i = 1; i < n; i++) {
        // if current meeting starts after earliest ending meeting
        if (arr[i].start >= top(heap)) {
            pop(heap, &heapSize);
        }

        // assign room (push end time)
        push(heap, &heapSize, arr[i].end);
    }

    printf("%d\n", heapSize);

    return 0;
}