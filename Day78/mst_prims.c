/*
 * Day 78: Minimum Spanning Tree - Prim's Algorithm
 * 
 * Problem: Find MST using Prim's algorithm
 * 
 * Time Complexity: O(V²) with adjacency matrix
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF INT_MAX

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INF, minIndex;
    
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("\nEdge \tWeight\n");
    int totalWeight = 0;
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("\nTotal MST Weight: %d\n", totalWeight);
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;
        
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    printMST(parent, graph, vertices);
}

int main() {
    printf("=== Day 78: Minimum Spanning Tree (Prim's) ===\n\n");
    
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    
    primMST(graph, 5);
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
