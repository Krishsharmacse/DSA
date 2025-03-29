#include <stdio.h>
#include <stdlib.h>

#define INF 99
#define MAX_VERTICES 8

typedef struct {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int V;
} Graph;

typedef struct {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} DisjointSet;

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

void printGraph(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        for (int j = 0; j < g->V; j++) {
            if (g->graph[i][j] != INF) {
                printf("Edge %d-%d with weight %d\n", i, j, g->graph[i][j]);
            }
        }
    }
}

void primMST(Graph* g) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < g->V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < g->V - 1; count++) {
        int u = -1;
        for (int v = 0; v < g->V; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        mstSet[u] = 1;

        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] != INF && !mstSet[v] && g->graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->graph[u][v];
            }
        }
    }

    printf("Prim's MST:\n");
    for (int i = 1; i < g->V; i++) {
        printf("Edge %d-%d with weight %d\n", parent[i], i, g->graph[i][parent[i]]);
    }
}

void makeSet(DisjointSet* ds, int vertices) {
    for (int i = 0; i < vertices; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
}

int findSet(DisjointSet* ds, int v) {
    if (v != ds->parent[v]) {
        ds->parent[v] = findSet(ds, ds->parent[v]);
    }
    return ds->parent[v];
}

void unionSets(DisjointSet* ds, int u, int v) {
    int rootU = findSet(ds, u);
    int rootV = findSet(ds, v);

    if (rootU != rootV) {
        if (ds->rank[rootU] > ds->rank[rootV]) {
            ds->parent[rootV] = rootU;
        } else if (ds->rank[rootU] < ds->rank[rootV]) {
            ds->parent[rootU] = rootV;
        } else {
            ds->parent[rootV] = rootU;
            ds->rank[rootU]++;
        }
    }
}

void kruskalMST(Graph* g) {
    DisjointSet ds;
    makeSet(&ds, g->V);

    typedef struct {
        int u, v, weight;
    } Edge;

    Edge edges[MAX_VERTICES * MAX_VERTICES];
    int edgeCount = 0;

    for (int i = 0; i < g->V; i++) {
        for (int j = i + 1; j < g->V; j++) {
            if (g->graph[i][j] != INF) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = g->graph[i][j];
                edgeCount++;
            }
        }
    }

    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    printf("Kruskal's MST:\n");
    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findSet(&ds, u) != findSet(&ds, v)) {
            printf("Edge %d-%d with weight %d\n", u, v, edges[i].weight);
            unionSets(&ds, u, v);
        }
    }
}

int main() {
    Graph g;
    initGraph(&g, 8);

    addEdge(&g, 0, 1, 10);
    addEdge(&g, 0, 2, 15);
    addEdge(&g, 0, 3, 20);
    addEdge(&g, 1, 2, 35);
    addEdge(&g, 1, 4, 25);
    addEdge(&g, 2, 4, 30);
    addEdge(&g, 3, 4, 10);
    addEdge(&g, 3, 5, 40);
    addEdge(&g, 4, 5, 50);
    addEdge(&g, 5, 6, 45);
    addEdge(&g, 6, 7, 55);
    addEdge(&g, 4, 7, 60);

    printf("Graph adjacency matrix:\n");
    printGraph(&g);

    primMST(&g);
    kruskalMST(&g);

    return 0;
}
