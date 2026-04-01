/*
 * Day 68: Topological Sort using Kahn's Algorithm (BFS)
 * 
 * Problem: Perform topological sorting using Kahn's Algorithm (indegree-based)
 * 
 * Time Complexity: O(V + E) - where V is vertices, E is edges
 * Space Complexity: O(V) - for queue and indegree array
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

// Queue structure
typedef struct {
    int arr[MAX_VERTICES];
    int front, rear;
} Queue;

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

// Queue operations
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int data) {
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
}

int dequeue(Queue* q) {
    int item = q->arr[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// Function to calculate indegree of all vertices
void calculateIndegree(Graph* graph, int indegree[]) {
    for (int i = 0; i < graph->vertices; i++) {
        indegree[i] = 0;
    }
    
    for (int i = 0; i < graph->vertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }
}

// Function to perform topological sort using Kahn's Algorithm
bool topologicalSort(Graph* graph) {
    int indegree[MAX_VERTICES];
    Queue q;
    initQueue(&q);
    
    // Calculate indegree of all vertices
    calculateIndegree(graph, indegree);
    
    // Enqueue all vertices with indegree 0
    for (int i = 0; i < graph->vertices; i++) {
        if (indegree[i] == 0) {
            enqueue(&q, i);
        }
    }
    
    int count = 0;  // Count of visited vertices
    int topOrder[MAX_VERTICES];
    
    // Process vertices
    while (!isQueueEmpty(&q)) {
        int vertex = dequeue(&q);
        topOrder[count++] = vertex;
        
        // Decrease indegree of neighbors
        Node* temp = graph->adjList[vertex];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            indegree[neighbor]--;
            
            // If indegree becomes 0, add to queue
            if (indegree[neighbor] == 0) {
                enqueue(&q, neighbor);
            }
            
            temp = temp->next;
        }
    }
    
    // Check if all vertices are visited (no cycle)
    if (count != graph->vertices) {
        printf("Graph contains cycle! Topological sort not possible.\n");
        return false;
    }
    
    // Print topological order
    printf("Topological Sort: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topOrder[i]);
    }
    printf("\n");
    
    return true;
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
    printf("=== Day 68: Topological Sort using Kahn's Algorithm ===\n\n");
    
    // Test Case 1: Simple DAG
    printf("Test Case 1: Course Prerequisites\n");
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
    
    // Test Case 3: Graph with cycle
    printf("\n=== Test Case 3: Graph with Cycle ===\n");
    Graph* graph3 = createGraph(3);
    addEdge(graph3, 0, 1);
    addEdge(graph3, 1, 2);
    addEdge(graph3, 2, 0);  // Creates cycle
    
    printGraph(graph3);
    printf("\n");
    topologicalSort(graph3);
    
    printf("\n=== Program Completed Successfully ===\n");
    
    return 0;
}

/*
 * Output:
 * === Day 68: Topological Sort using Kahn's Algorithm ===
 * 
 * Test Case 1: Course Prerequisites
 * 
 * Directed Graph:
 * Vertex 0: NULL
 * Vertex 1: NULL
 * Vertex 2: 3 -> NULL
 * Vertex 3: 1 -> NULL
 * Vertex 4: 1 -> 0 -> NULL
 * Vertex 5: 0 -> 2 -> NULL
 * 
 * Topological Sort: 4 5 0 2 3 1 
 * 
 * === Test Case 2: Linear Dependencies ===
 * 
 * Directed Graph:
 * Vertex 0: 1 -> NULL
 * Vertex 1: 2 -> NULL
 * Vertex 2: 3 -> NULL
 * Vertex 3: NULL
 * 
 * Topological Sort: 0 1 2 3 
 * 
 * === Test Case 3: Graph with Cycle ===
 * 
 * Directed Graph:
 * Vertex 0: 1 -> NULL
 * Vertex 1: 2 -> NULL
 * Vertex 2: 0 -> NULL
 * 
 * Graph contains cycle! Topological sort not possible.
 * 
 * === Program Completed Successfully ===
 * 
 * Complexity Analysis:
 * - Time Complexity: O(V + E) - visits each vertex and edge once
 * - Space Complexity: O(V) - for queue and indegree array
 * 
 * Key Points:
 * 1. Uses BFS approach with indegree
 * 2. Can detect cycles (if count != vertices)
 * 3. Processes vertices with indegree 0 first
 * 4. More intuitive than DFS approach
 * 
 * Algorithm:
 * 1. Calculate indegree of all vertices
 * 2. Enqueue vertices with indegree 0
 * 3. Process queue: remove vertex, decrease neighbor indegrees
 * 4. If neighbor indegree becomes 0, enqueue it
 * 5. If all vertices processed, topological sort exists
 */
