#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int path[MAX_VERTICES];
int pathIndex = 0;

// Initialize the graph
void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void addEdge(int from, int to) {
    graph[from][to] = 1;
}

// Depth-First Search
void dfs(int current, int destination, int vertices) {
    visited[current] = 1;
    path[pathIndex++] = current;

    if (current == destination) {
        // Print the path
        for (int i = 0; i < pathIndex; ++i) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < vertices; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                dfs(i, destination, vertices);
            }
        }
    }

    visited[current] = 0;
    pathIndex--;
}

int main() {
    int vertices, edges, from, to, source, destination;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeGraph(vertices);

    printf("Enter the edges (from to): \n");
    for (int i = 0; i < edges; ++i) {
        scanf("%d %d", &from, &to);
        addEdge(from, to);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("Enter destination vertex: ");
    scanf("%d", &destination);

    printf("Valid paths from %d to %d:\n", source, destination);
    dfs(source, destination, vertices);

    return 0;
}
