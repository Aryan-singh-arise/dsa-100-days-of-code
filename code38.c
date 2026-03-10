#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if(front == -1) return 0;
    return rear - front + 1;
}

void push_front(int value) {
    if(front == -1) {
        front = rear = 0;
    }
    else if(front > 0) {
        front--;
    }
    else {
        printf("Overflow\n");
        return;
    }
    deque[front] = value;
}

void push_back(int value) {
    if(rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if(front == -1) {
        front = rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = value;
}

void pop_front() {
    if(empty()) {
        printf("Deque Empty\n");
        return;
    }
    front++;
    if(front > rear) {
        front = rear = -1;
    }
}

void pop_back() {
    if(empty()) {
        printf("Deque Empty\n");
        return;
    }
    rear--;
    if(front > rear) {
        front = rear = -1;
    }
}

int get_front() {
    if(empty()) return -1;
    return deque[front];
}

int get_back() {
    if(empty()) return -1;
    return deque[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if(empty()) return;
    int i = front, j = rear;
    while(i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    if(empty()) return;
    for(int i = front; i <= rear; i++) {
        for(int j = i + 1; j <= rear; j++) {
            if(deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void printDeque() {
    if(empty()) {
        printf("Deque Empty\n");
        return;
    }
    for(int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    printDeque();

    pop_front();
    pop_back();

    printDeque();

    reverse();
    printDeque();

    sort();
    printDeque();

    clear();
    printDeque();

    return 0;
}