#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // initialize graph
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // input edges
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // remove if directed
    }

    int source;
    scanf("%d", &source);

    int dist[MAX], visited[MAX];

    for(int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;

        // pick min distance node
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // relax edges
        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && !visited[v]) {
                if(dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // print result
    for(int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}