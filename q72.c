/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m, source;
    Edge edges[MAX];
    int dist[MAX];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &source);

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    // Relax edges (n-1 times)
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }

    return 0;
}