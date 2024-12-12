#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main() {
    int numNodes, numEdges;
    printf("Enter the number of cities: ");
    scanf("%d", &numNodes);

    Graph *graph = createGraph(numNodes);

    printf("Enter the number of roads: ");
    scanf("%d", &numEdges);
    printf("Enter roads in the format (source destination weight):\n");

    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    int startNode, endNode;
    printf("Enter starting city and destination city: ");
    scanf("%d %d", &startNode, &endNode);

    dijkstra(graph, startNode, endNode);

    for (int i = 0; i < numNodes; i++) {
        free(graph->adjList[i]);
    }
    free(graph);

    return 0;
}
