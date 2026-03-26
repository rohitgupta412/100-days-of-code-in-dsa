/*
 * Day 62: Graph Representation - Adjacency List
 * 
 * Problem: Implement graph using adjacency list representation
 * 
 * Time Complexity:
 * - Add Edge: O(1)
 * - Check Edge: O(degree)
 * - Get All Neighbors: O(degree)
 * Space Complexity: O(V + E) - where V is vertices, E is edges
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct {
    int vertices;
    Node** adjList;
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjList = (Node**)malloc(vertices * sizeof(Node*));
    
    // Initialize all adjacency lists as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

// Function to add edge (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to add directed edge
void addDirectedEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Function to check if edge exists
bool hasEdge(Graph* graph, int src, int dest) {
    Node* temp = graph->adjList[src];
    while (temp != NULL) {
        if (temp->vertex == dest) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to print neighbors of a vertex
void printNeighbors(Graph* graph, int vertex) {
    printf("Neighbors of vertex %d: ", vertex);
    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get degree of a vertex
int getDegree(Graph* graph, int vertex) {
    int degree = 0;
    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        degree++;
        temp = temp->next;
    }
    return degree;
}

// Function to remove edge
void removeEdge(Graph* graph, int src, int dest) {
    // Remove dest from src's list
    Node* temp = graph->adjList[src];
    Node* prev = NULL;
    
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp != NULL) {
        if (prev == NULL) {
            graph->adjList[src] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
    
    // Remove src from dest's list (for undirected graph)
    temp = graph->adjList[dest];
    prev = NULL;
    
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp != NULL) {
        if (prev == NULL) {
            graph->adjList[dest] = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

// Main function
int main() {
    printf("=== Day 62: Graph - Adjacency List ===\n\n");
    
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
    
    return 0;
}

/*
 * Output:
 * === Day 62: Graph - Adjacency List ===
 * 
 * Creating undirected graph with 5 vertices (0-4)
 * 
 * Added edges: (0,1), (0,4), (1,2), (1,3), (1,4), (2,3), (3,4)
 * 
 * Adjacency List:
 * Vertex 0: 4 -> 1 -> NULL
 * Vertex 1: 4 -> 3 -> 2 -> 0 -> NULL
 * Vertex 2: 3 -> 1 -> NULL
 * Vertex 3: 4 -> 2 -> 1 -> NULL
 * Vertex 4: 3 -> 1 -> 0 -> NULL
 * 
 * Neighbors of vertex 0: 4 1 
 * Neighbors of vertex 1: 4 3 2 0 
 * Neighbors of vertex 2: 3 1 
 * Neighbors of vertex 3: 4 2 1 
 * Neighbors of vertex 4: 3 1 0 
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
 * - Space: O(V + E) - vertices + edges
 * - Add Edge: O(1)
 * - Check Edge: O(degree)
 * - Get Neighbors: O(degree)
 * 
 * Advantages:
 * 1. Space efficient for sparse graphs
 * 2. Fast iteration over neighbors
 * 3. Dynamic size
 * 
 * Disadvantages:
 * 1. Slower edge lookup than matrix
 * 2. More complex implementation
 */
