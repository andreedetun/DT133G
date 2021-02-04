#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int isEmpty(List* list) {
    return list->head == NULL;
}

List* initList() {
    return (List*)malloc(sizeof(List));
}

// TODO: We should probably check if the list in the param is NULL or not and initialize it with the "initList" function.
void insert(List* list, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;

    newNode->next = list->head;
    if(list->head != NULL) {
        list->head->prev = newNode;
    }

    list->head = newNode;
    list->tail = newNode->next;
    newNode->prev = NULL;
}

Node* search(List* list, int k) {
    for(;list->head; list->head = list->head->next){
        if(list->head->key == k) {
            return list->head;
        }
    }
    return NULL;
}