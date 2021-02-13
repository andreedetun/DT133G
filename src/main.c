#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"
#include "stack/stack.h"
#include "queue/queue.h"

int main(){
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 16);
    enqueue(queue, 19);

    printQueue(queue);
    freeQueue(queue);
    return 0;
}