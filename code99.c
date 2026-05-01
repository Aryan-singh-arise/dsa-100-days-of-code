#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    double time;
} Car;

// sort cars by position descending
int cmp(const void *a, const void *b) {
    Car *x = (Car *)a;
    Car *y = (Car *)b;
    return y->position - x->position;
}

int main() {
    int n, target;
    scanf("%d", &n);

    int position[n], speed[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    scanf("%d", &target);

    Car cars[n];

    // compute time to reach target
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // sort by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double currTime = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > currTime) {
            fleets++;
            currTime = cars[i].time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}