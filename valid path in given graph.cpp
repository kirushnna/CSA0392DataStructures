#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a graph node
struct Node {
    int data;
    struct Node* next;
};

// Create a new graph node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Define a structure for a graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

// Create a new graph with 'numVertices' vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node*)malloc(numVertices * sizeof(struct Node));
    graph->visited = (bool*)malloc(numVertices * sizeof(bool));

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Depth-first search to find a path
bool DFS(struct Graph* graph, int startVertex, int endVertex) {
    if (startVertex == endVertex) {
        return true; // Found a path
    }

    graph->visited[startVertex] = true;

    struct Node* temp = graph->adjLists[startVertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!graph->visited[adjVertex]) {
            if (DFS(graph, adjVertex, endVertex)) {
                return true; // Found a path
            }
        }
        temp = temp->next;
    }

    return false; // No path found
}

int main() {
    int numVertices = 6; // Change this value to match the number of vertices in your graph

    struct Graph* graph = createGraph(numVertices);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);

    int startVertex = 0; // Change this value to set the starting vertex
    int endVertex = 5;   // Change this value to set the ending vertex

    if (DFS(graph, startVertex, endVertex)) {
        printf("There is a valid path between vertex %d and vertex %d.\n", startVertex, endVertex);
    } else {
        printf("There is no valid path between vertex %d and vertex %d.\n", startVertex, endVertex);
    }

    return 0;
}
