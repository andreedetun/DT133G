#ifndef LAB_1_LIST_H
#define LAB_1_LIST_H

typedef struct node_t {
    int key;
    struct node_t *next;
    struct node_t *prev;
} Node;

typedef struct list_t {
    struct node_t *head;
    struct node_t *tail;

    // Length will be needed in queue.
    int length;
} List;

int isEmpty(List *list);

List *createList();

Node *createNode();

void insert(List *list, int key);

void insertNode(List *list, Node *node);

void unlinkNode(List *list, Node *node);

void delete(List *list, Node *node);

Node *search(List *list, int key);

Node *maximum(List *list);

Node *minimum(List *list);

Node *successor(List *list, Node *node);

Node *predecessor(List *list, Node *node);

// Helper functions
void printList(List *list);

void freeList(List *list);

#endif