// André Falk Edetun & Kevin Güvenal
#include <stdio.h>
#include <stdlib.h>
#include "../../src/list/list.h"
#include "../../src/stack/stack.h"
#include "../../src/queue/queue.h"

int main() {
    List *list = createList();
    insert(list, 1);
    insert(list, 3);
    printList(list);

    Node *node1 = search(list, 1);

    if (delete(list, node1) != NULL) {
        printf("Deleted node\n");
    } else {
        printf("Cant delete a node that doesn't exist\n");
    }

    if (delete(list, node1) != NULL) {
        printf("Deleted node\n");
    } else {
        printf("Cant delete a node that doesn't exist\n");
    }

    printList(list);

    Node *search3 = search(list, 3);
    if (search3 != NULL) {
        printf("Node with key 3 found: %d\n", search3->key);
    }

    Stack *stack = createStack();
    push(stack, 1);
    push(stack, 2);

    Queue *queue = createQueue();
    enqueue(queue, pop(stack)->key);
    enqueue(queue, pop(stack)->key);

    printf("item dequeued: %d\n", dequeue(queue)->key);
    return 0;
}