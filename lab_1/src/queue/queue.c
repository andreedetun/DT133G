// André Falk Edetun & Kevin Güvenal
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int queueEmpty(Queue *queue) {
    return queue->head == NULL ? 1 : 0;
}

Queue *createQueue() {
    Queue *tmp = (Queue *) malloc(sizeof(Queue));
    tmp->list = createList();
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->length = 0;

    return tmp;
}

void enqueue(Queue *queue, int key) {
    Node *newNode = createNode();
    newNode->key = key;
    insertNode(queue->list, newNode);
    queue->head = queue->list->head;
    queue->tail = queue->list->tail;
    queue->length = queue->list->length;
}

Node* dequeue(Queue *queue) {
    if (queueEmpty(queue)) {
        printf("Can't dequeue from an empty queue");
        return NULL;
    }

    Node* tmp = queue->head;
    delete(queue->list, queue->head);
    queue->head = queue->list->tail;
    queue->length = queue->list->length;
    return tmp;
}

void printQueue(Queue *queue) {
    printList(queue->list);
}

void freeQueue(Queue *queue) {
    if (queueEmpty(queue)) {
        printf("Can't free an empty queue.\n");
        return;
    }
    freeList(queue->list);
    // Now that all the nodes inside the queue are freed up we can safely
    // free the memory of the queue itself.
    free(queue);
}