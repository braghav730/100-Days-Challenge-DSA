/*Problem Statement Find shortest distances from source vertex in a weighted graph with non-negative weights. Input Format n m u v w source Output Format Distances to all vertices. Sample Input 5 6 1 2 2 1 3 4 2 3 1 2 4 7 3 5 3 4 5 1 1 Sample Output 0 2 3 9 6 Explanation Shortest distances computed via priority queue. give me c code*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int v, weight;
} Edge;

typedef struct {
    int node, dist;
} HeapNode;

Edge adj[MAX][MAX];
int adjSize[MAX];

HeapNode heap[MAX];
int heapSize = 0;

void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(HeapNode val) {
    heap[++heapSize] = val;
    int i = heapSize;

    while (i > 1 && heap[i].dist < heap[i / 2].dist) {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2 * i, right = 2 * i + 1;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }
    return top;
}

void dijkstra(int n, int source) {
    int dist[MAX];
    
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push((HeapNode){source, 0});

    while (heapSize > 0) {
        HeapNode curr = pop();
        int u = curr.node;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push((HeapNode){v, dist[v]});
            }
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adjSize[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]++] = (Edge){v, w};
        adj[v][adjSize[v]++] = (Edge){u, w}; // remove if directed
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}