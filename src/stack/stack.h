#ifndef LAB_1_STACKS_H
#define LAB_1_STACKS_H

#include "../list/list.h"

typedef struct stack_t {
    List *list;
    struct node_t *top;
} Stack;

int stackEmpty(Stack *stack);

Stack *createStack();

void push(Stack *stack, int key);

void pop(Stack *stack);

// Helper functions
void printStack(Stack *stack);

void freeStack(Stack* stack);

#endif //LAB_1_STACKS_H
