#include <stdio.h>
#include <limits.h>

#define MAX 100

int findTheCity(int n, int edges[][3], int m, int distanceThreshold) {
    
    int dist[MAX][MAX];

    // initialize
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX / 2; // avoid overflow
        }
    }

    // fill edges
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int city = -1;
    int minCount = INT_MAX;

    // count reachable cities
    for(int i = 0; i < n; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(i != j && dist[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // choose minimum, and in tie take larger index
        if(count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    return city;
}

int main() {
    int n = 4;
    int edges[][3] = {
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1}
    };
    int m = 4;
    int threshold = 4;

    int result = findTheCity(n, edges, m, threshold);
    printf("%d\n", result);

    return 0;
}