/*
 * Day 76: Count Connected Components in Graph
 * 
 * Problem: Count number of connected components in undirected graph
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

int countConnectedComponents(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    int count = 0;
    
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            count++;
        }
    }
    
    return count;
}

int main() {
    printf("=== Day 76: Count Connected Components ===\n\n");
    
    Graph* graph = createGraph(7);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 6);
    
    printf("Graph has %d connected components\n", countConnectedComponents(graph));
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
