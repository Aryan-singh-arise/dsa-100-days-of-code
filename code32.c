#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

// Display from top to bottom
void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    scanf("%d", &m);

    // Pop m times
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining elements
    display();

    return 0;
}