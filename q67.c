/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function to detect cycle
bool dfs(int node, int parent, int** adj, int n, bool* visited) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, adj, n, visited))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle found
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate adjacency matrix
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)calloc(n, sizeof(int));
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));

    // Check each component
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, n, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}