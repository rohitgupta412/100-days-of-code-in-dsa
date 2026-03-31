/*
 * Day 67: Topological Sort using DFS
 * 
 * Problem: Perform topological sorting of a Directed Acyclic Graph (DAG)
 * Topological Sort: Linear ordering where for every edge u->v, u comes before v
 * 
 * Time Complexity: O(V + E) - where V is vertices, E is edges
 * Space Complexity: O(V) - for stack and visited array
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

// Stack structure for storing topological order
typedef struct {
    int arr[MAX_VERTICES];
    int top;
} Stack;

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

// Stack operations
void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, int data) {
    s->arr[++s->top] = data;
}

int pop(Stack* s) {
    return s->arr[s->top--];
}

bool isStackEmpty(Stack* s) {
    return s->top == -1;
}

// DFS utility function for topological sort
void topologicalSortUtil(Graph* graph, int vertex, bool visited[], Stack* stack) {
    // Mark current node as visited
    visited[vertex] = true;
    
    // Explore all neighbors
    Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            topologicalSortUtil(graph, neighbor, visited, stack);
        }
        temp = temp->next;
    }
    
    // Push current vertex to stack after visiting all neighbors
    push(stack, vertex);
}

// Function to perform topological sort
void topologicalSort(Graph* graph) {
    Stack stack;
    initStack(&stack);
    bool visited[MAX_VERTICES] = {false};
    
    // Call DFS for all unvisited vertices
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, &stack);
        }
    }
    
    // Print topological order
    printf("Topological Sort: ");
    while (!isStackEmpty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");
}

// Function to print graph
void printGraph(Graph* graph) {
    printf("\nDirected Acyclic Graph (DAG):\n");
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
    printf("=== Day 67: Topological Sort using DFS ===\n\n");
    
    // Test Case 1: Simple DAG
    printf("Test Case 1: Course Prerequisites\n");
    printf("(Course dependencies: must take prerequisite before course)\n\n");
    
    Graph* graph1 = createGraph(6);
    addEdge(graph1, 5, 2);
    addEdge(graph1, 5, 0);
    addEdge(graph1, 4, 0);
    addEdge(graph1, 4, 1);
    addEdge(graph1, 2, 3);
    addEdge(graph1, 3, 1);
    
    printGraph(graph1);
    printf("\n");
    topologicalSort(graph1);
    
    // Test Case 2: Linear chain
    printf("\n=== Test Case 2: Linear Dependencies ===\n");
    Graph* graph2 = createGraph(4);
    addEdge(graph2, 0, 1);
    addEdge(graph2, 1, 2);
    addEdge(graph2, 2, 3);
    
    printGraph(graph2);
    printf("\n");
    topologicalSort(graph2);
    
    // Test Case 3: Multiple valid orderings
    printf("\n=== Test Case 3: Multiple Valid Orderings ===\n");
    Graph* graph3 = createGraph(4);
    addEdge(graph3, 0, 2);
    addEdge(graph3, 1, 2);
    addEdge(graph3, 2, 3);
    
    printGraph(graph3);
    printf("\n");
    topologicalSort(graph3);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 67: Topological Sort using DFS ===
 * 
 * Test Case 1: Course Prerequisites
 * (Course dependencies: must take prerequisite before course)
 * 
 * Directed Acyclic Graph (DAG):
 * Vertex 0: NULL
 * Vertex 1: NULL
 * Vertex 2: 3 -> NULL
 * Vertex 3: 1 -> NULL
 * Vertex 4: 1 -> 0 -> NULL
 * Vertex 5: 0 -> 2 -> NULL
 * 
 * Topological Sort: 5 4 2 3 1 0 
 * 
 * === Test Case 2: Linear Dependencies ===
 * 
 * Directed Acyclic Graph (DAG):
 * Vertex 0: 1 -> NULL
 * Vertex 1: 2 -> NULL
 * Vertex 2: 3 -> NULL
 * Vertex 3: NULL
 * 
 * Topological Sort: 0 1 2 3 
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(V + E) - visits each vertex and edge once
 * - Space Complexity: O(V) - for stack and visited array
 * 
 * Key Points:
 * 1. Only works on Directed Acyclic Graphs (DAG)
 * 2. Uses DFS and stack to store finishing times
 * 3. Multiple valid topological orderings possible
 * 4. Applications: Task scheduling, course prerequisites, build systems
 * 
 * Algorithm:
 * 1. Perform DFS from each unvisited vertex
 * 2. After visiting all neighbors, push vertex to stack
 * 3. Pop all vertices from stack for topological order
 */
