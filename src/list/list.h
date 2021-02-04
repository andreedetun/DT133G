typedef struct node_t {
    int key;
    struct node_t* next;
    struct node_t* prev;
} Node;

typedef struct list_t {
    // struct node_t* dataNode;
    struct node_t* head;
} List;

int isEmpty(List* list);

void insert(List* list, int key);