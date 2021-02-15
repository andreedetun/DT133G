// André Falk Edetun & Kevin Güvenal
#ifndef LAB_1_QUEUE_H
#define LAB_1_QUEUE_H

#include "../list/list.h"

typedef struct queue_t {
    List *list;
    struct node_t *head;
    struct node_t *tail;

    size_t length;
} Queue;

int queueEmpty(Queue *queue);

Queue *createQueue();

void enqueue(Queue *queue, int key);

Node* dequeue(Queue *queue);

// Helper functions
void printQueue(Queue *queue);

void freeQueue(Queue *queue);

#endif //LAB_1_QUEUE_H
