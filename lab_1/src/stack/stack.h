// André Falk Edetun & Kevin Güvenal
#ifndef LAB_1_STACKS_H
#define LAB_1_STACKS_H

#include "../list/list.h"

typedef struct stack_t {
    List *list;
    struct node_t *top;

    size_t length;
} Stack;

int stackEmpty(Stack *stack);

Stack *createStack();

void push(Stack *stack, int key);

Node* pop(Stack *stack);

// Helper functions
void printStack(Stack *stack);

void freeStack(Stack *stack);

#endif //LAB_1_STACKS_H
