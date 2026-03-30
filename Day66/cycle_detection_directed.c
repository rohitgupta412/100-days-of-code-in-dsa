/*
 * Day 66: Cycle Detection in Directed Graph
 * 
 * Problem: Detect if a directed graph contains a cycle using DFS
 * 
 * Time Complexity: O(V + E) - where V is vertices, E is edges
 * Space Complexity: O(V) - for recursion stack and visited arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Graph structure using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

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
    
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    return graph;
}

// Function to add directed edge
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// DFS utility function to detect cycle
bool isCyclicUtil(Graph* graph, int vertex, bool visited[], bool recStack[]) {
    // Mark current node as visited and add to recursion stack
    visited[vertex] = true;
    recStack[vertex] = true;
    
    // Explore all neighbors
    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        
        // If neighbor not visited, recurse
        if (!visited[neighbor]) {
            if (isCyclicUtil(graph, neighbor, visited, recStack)) {
                return true;
            }
        }
        // If neighbor is in recursion stack, cycle found
        else if (recStack[neighbor]) {
            return true;
        }
        
        temp = temp->next;
    }
    
    // Remove vertex from recursion stack
    recStack[vertex] = false;
    return false;
}

// Function to detect cycle in directed graph
bool hasCycle(Graph* graph) {
    bool visited[MAX_VERTICES] = {false};
    bool recStack[MAX_VERTICES] = {false};
    
    // Check for cycle in different DFS trees
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(graph, i, visited, recStack)) {
                return true;
            }
        }
    }
    
    return false;
}

// Function to print graph
void printGraph(Graph* graph) {
    printf("\nDirected Graph:\n");
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

// Main function
int main() {
    printf("=== Day 66: Cycle Detection in Directed Graph ===\n\n");
    
    // Test Case 1: Graph with cycle
    printf("Test Case 1: Graph with cycle\n");
    Graph* graph1 = createGraph(4);
    addEdge(graph1, 0, 1);
    addEdge(graph1, 1, 2);
    addEdge(graph1, 2, 3);
    addEdge(graph1, 3, 1);  // Creates cycle: 1 -> 2 -> 3 -> 1
    
    printGraph(graph1);
    printf("\nHas Cycle? %s\n", hasCycle(graph1) ? "Yes" : "No");
    
    // Test Case 2: Graph without cycle (DAG)
    printf("\n=== Test Case 2: Graph without cycle (DAG) ===\n");
    Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 0, 2);
    addEdge(graph2, 1, 3);
    addEdge(graph2, 2, 3);
    
    printGraph(graph2);
    printf("\nHas Cycle? %s\n", hasCycle(graph2) ? "Yes" : "No");
    
    // Test Case 3: Self loop
    printf("\n=== Test Case 3: Self loop ===\n");
    Graph* graph3 = createGraph(3);
    addEdge(graph3, 0, 1);
    addEdge(graph3, 1, 2);
    addEdge(graph3, 2, 2);  // Self loop
    
    printGraph(graph3);
    printf("\nHas Cycle? %s\n", hasCycle(graph3) ? "Yes" : "No");
    
    // Test Case 4: Disconnected graph with cycle
    printf("\n=== Test Case 4: Disconnected graph with cycle ===\n");
    Graph* graph4 = createGraph(6);
    addEdge(graph4, 0, 1);
    addEdge(graph4, 1, 2);
    addEdge(graph4, 3, 4);
    addEdge(graph4, 4, 5);
    addEdge(graph4, 5, 3);  // Cycle in second component
    
    printGraph(graph4);
    printf("\nHas Cycle? %s\n", hasCycle(graph4) ? "Yes" : "No");
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 66: Cycle Detection in Directed Graph ===
 * 
 * Test Case 1: Graph with cycle
 * 
 * Directed Graph:
 * Vertex 0: 1 -> NULL
 * Vertex 1: 2 -> NULL
 * Vertex 2: 3 -> NULL
 * Vertex 3: 1 -> NULL
 * 
 * Has Cycle? Yes
 * 
 * === Test Case 2: Graph without cycle (DAG) ===
 * 
 * Directed Graph:
 * Vertex 0: 2 -> 1 -> NULL
 * Vertex 1: 3 -> NULL
 * Vertex 2: 3 -> NULL
 * Vertex 3: NULL
 * 
 * Has Cycle? No
 * 
 * === Test Case 3: Self loop ===
 * 
 * Directed Graph:
 * Vertex 0: 1 -> NULL
 * Vertex 1: 2 -> NULL
 * Vertex 2: 2 -> NULL
 * 
 * Has Cycle? Yes
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(V + E) - visits each vertex and edge once
 * - Space Complexity: O(V) - for visited and recursion stack arrays
 * 
 * Key Points:
 * 1. Uses DFS with recursion stack
 * 2. If we reach a node already in recursion stack, cycle exists
 * 3. Different from undirected graph cycle detection
 * 4. Works for disconnected graphs too
 */
