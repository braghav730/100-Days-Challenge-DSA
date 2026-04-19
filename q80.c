/*Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->to = v;
    e1->weight = w;
    e1->next = adj[u];
    adj[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->to = u;
    e2->weight = w;
    e2->next = adj[v];
    adj[v] = e2;
}

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST(int n) {
    int key[MAX];
    int visited[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;  // Start from node 1
    int total_weight = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;
        total_weight += key[u];

        Edge* temp = adj[u];
        while (temp != NULL) {
            int v = temp->to;
            int w = temp->weight;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
            }
            temp = temp->next;
        }
    }

    return total_weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("%d\n", primMST(n));

    return 0;
}