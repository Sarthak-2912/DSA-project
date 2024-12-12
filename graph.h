#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NODES 100
#define INF 1000000 // A large number representing "infinity"

typedef struct {
    int destination;
    int weight;
} Edge;

typedef struct {
    int numNodes;
    Edge *adjList[MAX_NODES];
    int adjListSize[MAX_NODES];
} Graph;

Graph *createGraph(int nodes);
void addEdge(Graph *graph, int src, int dest, int weight);
void dijkstra(Graph *graph, int startNode, int endNode);

#endif
