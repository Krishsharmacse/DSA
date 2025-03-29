#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_VERTICES 8

typedef struct {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int V;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = INF;
        }
    }
}

void addEdge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

void printSolution(int dist[], int V) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

void dijkstra(Graph* g, int src) {
    int dist[MAX_VERTICES];
    int sptSet[MAX_VERTICES];
    
    for (int i = 0; i < g->V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    
    dist[src] = 0;

    for (int count = 0; count < g->V - 1; count++) {
        int u = -1;
        
        for (int v = 0; v < g->V; v++) {
            if (!sptSet[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }

        sptSet[u] = 1;

        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] != INF && !sptSet[v] && dist[u] != INF && dist[u] + g->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }

    printSolution(dist, g->V);
}

void bellmanFord(Graph* g, int src) {
    int dist[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 1; i < g->V; i++) {
        for (int u = 0; u < g->V; u++) {
            for (int v = 0; v < g->V; v++) {
                if (g->graph[u][v] != INF && dist[u] != INF && dist[u] + g->graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + g->graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < g->V; u++) {
        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] != INF && dist[u] != INF && dist[u] + g->graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    printSolution(dist, g->V);
}

int main() {
    Graph g;
    initGraph(&g, 6);

    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 2, 20);
    addEdge(&g, 1, 2, 30);
    addEdge(&g, 1, 3, 10);
    addEdge(&g, 2, 4, 50);
    addEdge(&g, 3, 4, 10);
    addEdge(&g, 3, 5, 60);
    addEdge(&g, 4, 5, 30);

    printf("Dijkstra's Algorithm:\n");
    dijkstra(&g, 0);

    printf("\nBellman-Ford Algorithm:\n");
    bellmanFord(&g, 0);

    return 0;
}
