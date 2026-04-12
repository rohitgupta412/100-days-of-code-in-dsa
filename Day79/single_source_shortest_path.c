/*
 * Day 79: Single Source Shortest Path (BFS for unweighted graph)
 * 
 * Problem: Find shortest path from source to all vertices
 * 
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int vertices;
    Node** adjList;
} Graph;

typedef struct {
    int arr[MAX_VERTICES];
    int front, rear;
} Queue;

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

void shortestPath(Graph* graph, int src) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES] = {false};
    
    for (int i = 0; i < graph->vertices; i++) {
        dist[i] = INT_MAX;
    }
    
    Queue q;
    initQueue(&q);
    
    dist[src] = 0;
    visited[src] = true;
    enqueue(&q, src);
    
    while (!isQueueEmpty(&q)) {
        int u = dequeue(&q);
        
        Node* temp = graph->adjList[u];
        while (temp != NULL) {
            int v = temp->vertex;
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                enqueue(&q, v);
            }
            temp = temp->next;
        }
    }
    
    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: %d\n", i, dist[i] == INT_MAX ? -1 : dist[i]);
    }
}

int main() {
    printf("=== Day 79: Single Source Shortest Path ===\n\n");
    
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    
    shortestPath(graph, 0);
    
    printf("\n=== Program Completed Successfully ===\n");
    return 0;
}
