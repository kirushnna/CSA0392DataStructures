#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Find operation of union-find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union operation of union-find
void unionSets(struct Subset subsets[], int x, int y) {
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    else {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

// Comparison function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the minimum spanning tree
void kruskal(struct Edge edges[], int V, int E) {
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    qsort(edges, E, sizeof(edges[0]), compareEdges);

    struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));
    int resultIndex = 0;

    for (int e = 0; e < E; ++e) {
        int srcRoot = find(subsets, edges[e].src);
        int destRoot = find(subsets, edges[e].dest);

        if (srcRoot != destRoot) {
            result[resultIndex++] = edges[e];
            unionSets(subsets, srcRoot, destRoot);
        }
    }

    printf("Minimum Spanning Tree:\n");
    for (int i = 0; i < V - 1; ++i)
        printf("(%d, %d) -> %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
    free(result);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}
