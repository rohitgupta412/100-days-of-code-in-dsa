#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int parent, int vis[], int adj[][100], int V) {
    vis[node] = 1;
    
    for(int i = 0; i < V; i++) {
        if(adj[node][i]) {
            if(!vis[i]) {
                if(dfs(i, node, vis, adj, V))
                    return 1;
            }
            else if(i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int isCycle(int V, int adj[][100]) {
    int vis[100] = {0};
    
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj, V))
                return 1;
        }
    }
    return 0;
}

int main() {
    int V = 5;
    int adj[100][100] = {0};
    
    // Creating a graph with cycle
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[4][0] = adj[0][4] = 1;
    
    if(isCycle(V, adj))
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");
    
    return 0;
}
