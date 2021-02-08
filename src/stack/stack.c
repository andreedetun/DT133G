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

    return tmp;
}

void push(Stack *stack, int key) {
    Node *newNode = createNode();
    newNode->key = key;
    insertNode(stack->list, newNode);
    stack->top = stack->list->tail;

    // increase length of the list inside the stack.
    stack->list->length++;
}

void pop(Stack *stack) {
    delete(stack->list, stack->top);
    stack->top = stack->list->tail;

    // decrease length of the list inside the stack.
    stack->list->length--;
}

void printStack(Stack *stack) {
    printList(stack->list);
}