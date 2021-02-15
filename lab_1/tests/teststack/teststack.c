// André Falk Edetun & Kevin Güvenal
#include <stdio.h>
#include <stdlib.h>
#include "../../src/stack/stack.h"

void test1() {
    Stack *andrePersonalNum = createStack();
    push(andrePersonalNum, 0);
    push(andrePersonalNum, 1);
    push(andrePersonalNum, 2);
    push(andrePersonalNum, 0);
    push(andrePersonalNum, 1);
    push(andrePersonalNum, 0);

    Stack *kevinPersonalNum = createStack();
    push(kevinPersonalNum, 5);
    push(kevinPersonalNum, 1);
    push(kevinPersonalNum, 6);
    push(kevinPersonalNum, 0);
    push(kevinPersonalNum, 1);
    push(kevinPersonalNum, 0);

    printStack(andrePersonalNum);
    printStack(kevinPersonalNum);

    freeStack(andrePersonalNum);
    freeStack(kevinPersonalNum);
}

int main() {
    test1();
    return 0;
}