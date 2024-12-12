#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct {
    int node;
    int distance;
} QueueNode;

typedef struct {
    QueueNode *nodes;
    int size;
    int capacity;
} PriorityQueue;

void initializeQueue(PriorityQueue *pq, int capacity);
void insert(PriorityQueue *pq, int node, int distance);
int extractMin(PriorityQueue *pq);
int isEmpty(PriorityQueue *pq);
void freeQueue(PriorityQueue *pq);

#endif
