typedef struct node_t {
    int key;
    struct node_t* next;
    struct node_t* prev;
} Node;

typedef struct list_t {
    struct node_t* head;
    struct node_t* tail;
} List;

int isEmpty(List* list);

List* initList();

void insert(List* list, int key);

Node* search(List* list, int key);

void freeList(List* list);