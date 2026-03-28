#include <stdio.h>
#include <stdlib.h>

void bfs(int start, int adj[][100], int vis[], int V) {
    int queue[100];
    int front = 0, rear = 0;
    
    vis[start] = 1;
    queue[rear++] = start;
    
    printf("BFS Traversal: ");
    
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        
        for (int i = 0; i < V; i++) {
            if (adj[node][i] && !vis[i]) {
                vis[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    
    int adj[100][100] = {0};
    int vis[100] = {0};
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    bfs(0, adj, vis, V);
    
    return 0;
}
