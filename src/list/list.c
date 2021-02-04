#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int isEmpty(List* list) {
    return list->head == NULL;
}

List* initList() {
    List* tmp = (List*)malloc(sizeof(List));
    tmp->head = NULL;
    tmp->tail = NULL;
    return tmp;
}

// TODO: We should probably check if the list in the param is NULL or not and initialize it with the "initList" function.
// TODO: We also need to sort the list
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

Node* search(List* list, int key) {
    Node* current = list->head;
    for(;current; current = current->next) {
        if(current->key == key){
            return current;
        }
    }
    return NULL;
}

void freeList(List* list) {
    Node* current = list->head;
    Node* tmp = NULL;
    while(current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(list);
}