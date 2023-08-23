#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

// DFS traversal
void DFS(int graph[MAX_NODES][MAX_NODES], bool visited[MAX_NODES], int nodes, int current) {
    printf("%d ", current);
    visited[current] = true;

    for (int i = 0; i < nodes; i++) {
        if (graph[current][i] && !visited[i]) {
            DFS(graph, visited, nodes, i);
        }
    }
}

int main() {
    int nodes, edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1; // Assuming an undirected graph
    }

    bool visited[MAX_NODES] = {false};

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("DFS traversal starting from node %d: ", startNode);
    DFS(graph, visited, nodes, startNode);

    return 0;
}

