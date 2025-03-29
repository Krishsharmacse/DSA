#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 15

typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue overflow\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

typedef struct Graph {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;
} Graph;

void initGraph(Graph* g, int numVertices) {
    g->numVertices = numVertices;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void printGraph(Graph* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertex %d:", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == 1) {
                printf(" %d", j);
            }
        }
        printf("\n");
    }
}

void BFS(Graph* g, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    Queue q;
    initQueue(&q);
    
    visited[startVertex] = 1;
    enqueue(&q, startVertex);
    
    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(Graph* g, int startVertex, int visited[MAX_VERTICES]) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 6);
    
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);
    addEdge(&g, 3, 5);
    
    printf("Graph adjacency list:\n");
    printGraph(&g);

    printf("\nBFS starting from vertex 0:\n");
    BFS(&g, 0);
    
    printf("\nDFS starting from vertex 0:\n");
    int visited[MAX_VERTICES] = {0};
    DFS(&g, 0, visited);

    return 0;
}
