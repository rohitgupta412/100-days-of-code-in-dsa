#include <stdio.h>
#include <limits.h>

#define V 5

void bellmanFord(int graph[][3], int E, int src) {
    int dist[V];
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    
    dist[src] = 0;
    
    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    
    // Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = graph[j][0];
        int v = graph[j][1];
        int weight = graph[j][2];
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }
    
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[][3] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };
    
    int E = sizeof(graph) / sizeof(graph[0]);
    
    bellmanFord(graph, E, 0);
    
    return 0;
}
