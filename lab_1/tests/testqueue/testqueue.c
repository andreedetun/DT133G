// André Falk Edetun & Kevin Güvenal
#include <stdio.h>
#include <stdlib.h>
#include "../../src/queue/queue.h"

void test1() {
    Queue *queue = createQueue();
    enqueue(queue, 0);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 0);
    enqueue(queue, 1);
    enqueue(queue, 0);

    printQueue(queue);
    freeQueue(queue);
}

int main() {
    test1();
    return 0;
}