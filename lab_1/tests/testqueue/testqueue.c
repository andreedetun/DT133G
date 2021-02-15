// André Falk Edetun & Kevin Güvenal
#include <stdio.h>
#include <stdlib.h>
#include "../../src/queue/queue.h"

void test1() {
    Queue *andrePersonalNum = createQueue();
    enqueue(andrePersonalNum, 0);
    enqueue(andrePersonalNum, 1);
    enqueue(andrePersonalNum, 2);
    enqueue(andrePersonalNum, 0);
    enqueue(andrePersonalNum, 1);
    enqueue(andrePersonalNum, 0);

    Queue *kevinPersonalNum = createQueue();
    enqueue(kevinPersonalNum, 15);
    enqueue(kevinPersonalNum, 1);
    enqueue(kevinPersonalNum, 6);
    enqueue(kevinPersonalNum, 0);
    enqueue(kevinPersonalNum, 1);
    enqueue(kevinPersonalNum, 0);

    printQueue(andrePersonalNum);
    printQueue(kevinPersonalNum);

    freeQueue(andrePersonalNum);
    freeQueue(kevinPersonalNum);
}

int main() {
    test1();
    return 0;
}