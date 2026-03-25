/*
 * Day 61: Graph Representation - Adjacency Matrix
 * 
 * Problem: Implement graph using adjacency matrix representation
 * 
 * Time Complexity: 
 * - Add Edge: O(1)
 * - Check Edge: O(1)
 * - Get All Neighbors: O(V)
 * Space Complexity: O(V²) - where V is number of vertices
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Graph structure using adjacency matrix
typedef struct {
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    // Initialize all edges to 0 (no edge)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Function to add edge (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->matrix[src][dest] = 1;
        graph->matrix[dest][src] = 1;  // For undirected graph
    }
}

// Function to add directed edge
void addDirectedEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->matrix[src][dest] = 1;
    }
}

// Function to check if edge exists
bool hasEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        return graph->matrix[src][dest] == 1;
    }
    return false;
}

// Function to remove edge
void removeEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->matrix[src][dest] = 0;
        graph->matrix[dest][src] = 0;  // For undirected graph
    }
}

// Function to print adjacency matrix
void printGraph(Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print neighbors of a vertex
void printNeighbors(Graph* graph, int vertex) {
    printf("Neighbors of vertex %d: ", vertex);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[vertex][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to get degree of a vertex
int getDegree(Graph* graph, int vertex) {
    int degree = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[vertex][i] == 1) {
            degree++;
        }
    }
    return degree;
}

// Main function
int main() {
    printf("=== Day 61: Graph - Adjacency Matrix ===\n\n");
    
    // Create graph with 5 vertices
    Graph* graph = createGraph(5);
    
    printf("Creating undirected graph with 5 vertices (0-4)\n");
    
    // Add edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    printf("\nAdded edges: (0,1), (0,4), (1,2), (1,3), (1,4), (2,3), (3,4)\n");
    
    // Print graph
    printGraph(graph);
    
    // Print neighbors
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printNeighbors(graph, i);
    }
    
    // Check edges
    printf("\nEdge Checks:\n");
    printf("Edge (0,1) exists? %s\n", hasEdge(graph, 0, 1) ? "Yes" : "No");
    printf("Edge (0,2) exists? %s\n", hasEdge(graph, 0, 2) ? "Yes" : "No");
    
    // Get degrees
    printf("\nVertex Degrees:\n");
    for (int i = 0; i < 5; i++) {
        printf("Degree of vertex %d: %d\n", i, getDegree(graph, i));
    }
    
    // Remove edge
    printf("\nRemoving edge (1,4)...\n");
    removeEdge(graph, 1, 4);
    printGraph(graph);
    
    printf("\n=== Test Case 2: Directed Graph ===\n");
    Graph* dirGraph = createGraph(4);
    
    addDirectedEdge(dirGraph, 0, 1);
    addDirectedEdge(dirGraph, 0, 2);
    addDirectedEdge(dirGraph, 1, 2);
    addDirectedEdge(dirGraph, 2, 0);
    addDirectedEdge(dirGraph, 2, 3);
    addDirectedEdge(dirGraph, 3, 3);
    
    printf("\nDirected Graph:\n");
    printGraph(dirGraph);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    free(graph);
    free(dirGraph);
    
    return 0;
}

/*
 * Output:
 * === Day 61: Graph - Adjacency Matrix ===
 * 
 * Creating undirected graph with 5 vertices (0-4)
 * 
 * Added edges: (0,1), (0,4), (1,2), (1,3), (1,4), (2,3), (3,4)
 * 
 * Adjacency Matrix:
 *    0 1 2 3 4 
 * 0: 0 1 0 0 1 
 * 1: 1 0 1 1 1 
 * 2: 0 1 0 1 0 
 * 3: 0 1 1 0 1 
 * 4: 1 1 0 1 0 
 * 
 * Neighbors of vertex 0: 1 4 
 * Neighbors of vertex 1: 0 2 3 4 
 * Neighbors of vertex 2: 1 3 
 * Neighbors of vertex 3: 1 2 4 
 * Neighbors of vertex 4: 0 1 3 
 * 
 * Edge Checks:
 * Edge (0,1) exists? Yes
 * Edge (0,2) exists? No
 * 
 * Vertex Degrees:
 * Degree of vertex 0: 2
 * Degree of vertex 1: 4
 * Degree of vertex 2: 2
 * Degree of vertex 3: 3
 * Degree of vertex 4: 3
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Space: O(V²) - matrix storage
 * - Add Edge: O(1)
 * - Check Edge: O(1)
 * - Get Neighbors: O(V)
 * 
 * Advantages:
 * 1. Fast edge lookup O(1)
 * 2. Simple implementation
 * 3. Good for dense graphs
 * 
 * Disadvantages:
 * 1. Space inefficient for sparse graphs
 * 2. O(V²) space always needed
 */
