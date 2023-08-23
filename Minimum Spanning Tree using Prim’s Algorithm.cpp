#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 100

// Prim's algorithm
void primMST(int graph[MAX_NODES][MAX_NODES], int nodes) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];

    for (int i = 0; i < nodes; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < nodes - 1; i++) {
        int minKey = INT_MAX, minIndex;

        for (int j = 0; j < nodes; j++) {
            if (!mstSet[j] && key[j] < minKey) {
                minKey = key[j];
                minIndex = j;
            }
        }

        mstSet[minIndex] = true;

        for (int k = 0; k < nodes; k++) {
            if (graph[minIndex][k] && !mstSet[k] && graph[minIndex][k] < key[k]) {
                parent[k] = minIndex;
                key[k] = graph[minIndex][k];
            }
        }
    }

    printf("Edge\tWeight\n");
    for (int i = 1; i < nodes; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    int graph[MAX_NODES][MAX_NODES];

    // Initialize the graph with zeros
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix (row by row):\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, nodes);

    return 0;
}

