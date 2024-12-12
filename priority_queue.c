#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

void initializeQueue(PriorityQueue *pq, int capacity) {
    pq->nodes = (QueueNode *)malloc(capacity * sizeof(QueueNode));
    pq->size = 0;
    pq->capacity = capacity;
}

void insert(PriorityQueue *pq, int node, int distance) {
    pq->nodes[pq->size].node = node;
    pq->nodes[pq->size].distance = distance;
    pq->size++;
    int i = pq->size - 1;
    while (i > 0 && pq->nodes[i].distance < pq->nodes[(i - 1) / 2].distance) {
        QueueNode temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        pq->nodes[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int extractMin(PriorityQueue *pq) {
    int minNode = pq->nodes[0].node;
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;

    int i = 0;
    while (2 * i + 1 < pq->size) {
        int smallest = i;
        if (pq->nodes[2 * i + 1].distance < pq->nodes[smallest].distance) {
            smallest = 2 * i + 1;
        }
        if (2 * i + 2 < pq->size && pq->nodes[2 * i + 2].distance < pq->nodes[smallest].distance) {
            smallest = 2 * i + 2;
        }
        if (smallest == i) break;

        QueueNode temp = pq->nodes[i];
        pq->nodes[i] = pq->nodes[smallest];
        pq->nodes[smallest] = temp;
        i = smallest;
    }
    return minNode;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void freeQueue(PriorityQueue *pq) {
    free(pq->nodes);
}
