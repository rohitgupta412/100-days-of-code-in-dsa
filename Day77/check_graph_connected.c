/*
 * Day 77: Check if Graph is Connected
 * 
 * Problem: Check if all vertices in undirected graph are connected
 * 
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int vertices;
    Node** adjList;
} Graph;

Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void DFS(Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    
    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

bool isConnected(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    
    // Start DFS from vertex 0
    DFS(graph, 0, visited);
    
    // Check if all vertices are visited
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    printf("=== Day 77: Check if Graph is Connected ===\n\n");
    
    // Test Case 1: Connected graph
    Graph* graph1 = createGraph(4);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 3);
    
    printf("Test Case 1: %s\n", isConnected(graph1) ? "Connected" : "Not Connected");
    
    // Test Case 2: Disconnected graph
    Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 2, 3);
    
    printf("Test Case 2: %s\n", isConnected(graph2) ? "Connected" : "Not Connected");
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
