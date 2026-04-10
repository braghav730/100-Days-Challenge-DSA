/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int size;
} PQ;

// Simple priority queue (min-heap behavior manually)
void push(PQ *pq, int node, int weight) {
    pq->edges[pq->size].node = node;
    pq->edges[pq->size].weight = weight;
    pq->size++;
}

int extractMin(PQ *pq) {
    int minIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->edges[i].weight < pq->edges[minIndex].weight)
            minIndex = i;
    }
    int node = pq->edges[minIndex].node;
    pq->edges[minIndex] = pq->edges[pq->size - 1];
    pq->size--;
    return node;
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    PQ pq;
    pq.size = 0;
    push(&pq, src, 0);

    while (pq.size > 0) {
        int u = extractMin(&pq);

        if (visited[u]) continue;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    push(&pq, v, dist[v]);
                }
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}