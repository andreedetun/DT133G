#include <stdio.h>
#include <stdlib.h>
#include "../../src/stack/stack.h"

void test1() {
    Stack *stack = createStack();
    push(stack, 0);
    push(stack, 1);
    push(stack, 2);
    push(stack, 0);
    push(stack, 1);
    push(stack, 0);

    printStack(stack);
    freeStack(stack);
}

int main() {
    test1();
    return 0;
}