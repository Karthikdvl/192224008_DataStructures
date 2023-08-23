#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

// Queue implementation
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int item) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = item;
    }
}

int dequeue(Queue *q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS traversal
void BFS(int graph[MAX_NODES][MAX_NODES], int nodes, int start) {
    bool visited[MAX_NODES] = {false};
    Queue q;
    initializeQueue(&q);

    visited[start] = true;
    enqueue(&q, start);

    while (!isQueueEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < nodes; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
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

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    BFS(graph, nodes, startNode);

    return 0;
}

