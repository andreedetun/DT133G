// André Falk Edetun & Kevin Güvenal
#ifndef LAB_1_LIST_H
#define LAB_1_LIST_H
typedef struct list_t List;



typedef struct node_t {
    int key;
    int weight;
    int distance;
    struct node_t *pi;
    struct node_t *src;
    struct node_t *dest;
    struct list_t *edges;
    struct node_t *next;
    struct node_t *prev;
} Node;

typedef struct list_t {
    struct node_t *head;
    struct node_t *tail;

    // Length will be needed in queue.
    size_t length;
} List;

int isEmpty(List *list);

List *createList();

Node *createNode();

void insert(List *list, int key);

void insertNode(List *list, Node *node);

void unlinkNode(List *list, Node *node);

Node* delete(List *list, Node *node);

Node *search(List *list, int key);

Node *maximum(List *list);

Node *minimum(List *list);

Node *successor(List *list, Node *node);

Node *predecessor(List *list, Node *node);

// Helper functions
void printList(List *list);

void freeList(List *list);

#endif