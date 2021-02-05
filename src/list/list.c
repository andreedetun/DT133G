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
// TODO: We also need to sort the list (??)
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

// The unlink function is mainly written to be used inside the delete function.
// Consider not making it global.
void unlinkNode(List* list, Node* node) {
    // Make sure the list we are trying to unlink a node from is NOT empty.
    if(isEmpty(list)) {
        printf("Can't unlink a node from an empty list.\n");
        return;
    }

    if(node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if(node->next != NULL) {
        node->next->prev = node->prev;
    }
}

// The delete function requires the use of the search function to retrieve a pointer
// to the node that should be deleted. We should consider making an override of the delete
// function if we wish to delete a node based on some other params, tho the logic stays the same.
void delete(List* list, Node* node) {
    // Make sure the list we are trying to delete a node from is NOT empty.
    if(isEmpty(list)) {
        printf("Can't delete a node from an empty list.\n");
        return;
    }
    unlinkNode(list, node);
    // Make sure to free the memory of the node that has been unlinked.
    free(node);
}

Node* search(List* list, int key) {
    // Make sure the list we are trying to search is NOT empty.
    if(isEmpty(list)) {
        printf("Can't search an empty list.\n");
        return NULL;
    }

    Node* current = list->head;
    for(;current; current = current->next) {
        if(current->key == key){
            return current;
        }
    }
    return NULL;
}

void printList(List* list) {
    Node* current = list->head;
    for(; current; current = current->next) {
        printf("[%d]->", current->key);
    }
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