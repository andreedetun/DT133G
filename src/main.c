#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"
#include "stack/stack.h"

int main(){
    Stack *stack = createStack();
    push(stack, 2);
    push(stack, 22);
    push(stack, 12);
    push(stack, 40);

    printStack(stack);
    printf("len: %d\n", stack->list->length);
    return 0;
}