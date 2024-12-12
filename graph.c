#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "priority_queue.h"

Graph *createGraph(int nodes) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numNodes = nodes;

    for (int i = 0; i < nodes; i++) {
        graph->adjList[i] = (Edge *)malloc(MAX_NODES * sizeof(Edge));
        graph->adjListSize[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
    graph->adjList[src][graph->adjListSize[src]].destination = dest;
    graph->adjList[src][graph->adjListSize[src]].weight = weight;
    graph->adjListSize[src]++;
    
    graph->adjList[dest][graph->adjListSize[dest]].destination = src;
    graph->adjList[dest][graph->adjListSize[dest]].weight = weight;
    graph->adjListSize[dest]++;
}

void dijkstra(Graph *graph, int startNode, int endNode) {
    int distances[MAX_NODES], parents[MAX_NODES];
    PriorityQueue pq;
    
    initializeQueue(&pq, graph->numNodes);

    for (int i = 0; i < graph->numNodes; i++) {
        distances[i] = INF;
        parents[i] = -1;
    }
    distances[startNode] = 0;
    insert(&pq, startNode, 0);

    while (!isEmpty(&pq)) {
        int current = extractMin(&pq);

        if (current == endNode) break;

        for (int i = 0; i < graph->adjListSize[current]; i++) {
            Edge edge = graph->adjList[current][i];
            int newDist = distances[current] + edge.weight;

            if (newDist < distances[edge.destination]) {
                distances[edge.destination] = newDist;
                parents[edge.destination] = current;
                insert(&pq, edge.destination, newDist);
            }
        }
    }

    // Display the shortest path and distance
    if (distances[endNode] != INF) {
        printf("Shortest distance from %d to %d is %d\n", startNode, endNode, distances[endNode]);
        printf("Path: ");
        int path[MAX_NODES], path_size = 0;
        for (int at = endNode; at != -1; at = parents[at]) {
            path[path_size++] = at;
        }
        for (int i = path_size - 1; i >= 0; i--) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found from %d to %d.\n", startNode, endNode);
    }
    freeQueue(&pq);
}
