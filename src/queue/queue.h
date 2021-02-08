
#ifndef LAB_1_QUEUE_H
#define LAB_1_QUEUE_H

#include "../list/list.h"

typedef struct queue_t {
    List *list;
    struct node_t *head;
    struct node_t *tail;
} Queue;

void enqueue(Queue *queue);

void dequeue(Queue *queue);

#endif //LAB_1_QUEUE_H
