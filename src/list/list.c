#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int isEmpty(List* list) {
    return list->head == NULL;
}

List* initList() {
    return (List*)malloc(sizeof(List));
}

void insert(List* list, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;

    newNode->next = list->head;
    if(list->head != NULL) {
        list->head->prev = newNode;
    }

    list->head = newNode;
    newNode->prev = NULL;
}