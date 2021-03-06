// André Falk Edetun & Kevin Güvenal
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stackEmpty(Stack *stack) {
    return stack->top == NULL ? 1 : 0;
}

Stack *createStack() {
    Stack *tmp = (Stack *) malloc(sizeof(Stack));
    tmp->list = createList();
    tmp->top = NULL;
    tmp->length = 0;

    return tmp;
}

void push(Stack *stack, int key) {
    Node *newNode = createNode();
    newNode->key = key;
    insertNode(stack->list, newNode);
    stack->top = stack->list->tail;
    stack->length = stack->list->length;
}

Node* pop(Stack *stack) {
    Node* tmp = stack->top;

    delete(stack->list, stack->top);
    stack->top = stack->list->tail;
    stack->length = stack->list->length;

    return tmp;
}

void printStack(Stack *stack) {
    printList(stack->list);
}

void freeStack(Stack *stack) {
    if (stackEmpty(stack)) {
        printf("Can't free an empty stack.\n");
        return;
    }
    freeList(stack->list);
    // Now that all the nodes inside the stack are freed up we can safely
    // free the memory of the stack itself.
    free(stack);
}
