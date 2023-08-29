#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numNodes;
    struct Node* adjList[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Depth-First Search traversal
void dfs(struct Graph* graph, int node, int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* curr = graph->adjList[node];
    while (curr != NULL) {
        int neighbor = curr->data;
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
        curr = curr->next;
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = 6; // Change this to the actual number of nodes

    for (int i = 0; i < graph->numNodes; i++) {
        graph->adjList[i] = NULL;
    }

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    int visited[MAX_NODES] = {0};
    printf("DFS traversal from starting node 0:\n");
    dfs(graph, 0, visited);

    return 0;
}
