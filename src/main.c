#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"
#include "stack/stack.h"

int main(){
    Stack *stack = createStack();
    push(stack, 2);
    push(stack, 22);
    push(stack, 24);
    push(stack, 40);

    printStack(stack);
    return 0;
}