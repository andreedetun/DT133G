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

// TODO: We might need to sort the list on insertion. (???)ßßß
void insert(List* list, int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;

    if(isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
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

// The delete function requires a pointer to the node that should be deleted.
// We should consider making an override of the delete
// function if we wish to delete a node based on some other params, though the delete logic stays the same.
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

Node* maximum(List* list) {
    if(isEmpty(list)) {
        printf("Can't find the maximum node of an empty list.\n");
        return NULL;
    }

    Node* current = list->head;
    Node* max = current;

    for(; current; current = current->next) {
        if(current->key > max->key) {
            max = current;
        }
    }
    return max;
}

Node* minimum(List* list) {
    if(isEmpty(list)) {
        printf("Can't find the minimum node of an empty list.\n");
        return NULL;
    }

    Node* current = list->head;
    Node* min = current;

    for(; current; current = current->next) {
        if(current->key < min->key) {
            min = current;
        }
    }
    return min;
}

Node* successor(List* list, Node* node) {
    if(isEmpty(list)) {
        printf("Can't find a successor of a node from an empty list.\n");
        return NULL;
    }

    Node* current = node;
    Node* tmp = node;
    Node* max = maximum(list);

    if(current->next == NULL) {
        current = list->head;
    }

    // The maximum node wont have a successor so we need to return NULL in that case.
    if(current == max) {
        return NULL;
    }

    for(; tmp; tmp = tmp->next) {
        if(tmp->key > current->key) {
            return tmp;
        }
    }
    return NULL;
}

Node* predecessor(List* list, Node* node) {
    if(isEmpty(list)) {
        printf("Can't find a predecessor of a node from an empty list.\n");
        return NULL;
    }

    Node* current = node;
    Node* tmp = node;
    Node* min = minimum(list);

    if(current->prev == NULL) {
        current = list->tail;
    }

    // The minimum node wont have a predecessor so we need to return NULL in that case.
    if(current == min) {
        return NULL;
    }

    for(; tmp; tmp = tmp->prev) {
        if(tmp->key < current->key) {
            return tmp;
        }
    }
    return NULL;
}

void printList(List* list) {
    if(isEmpty(list)) {
        printf("Can't print an empty list.\n");
        return;
    }

    Node* current = list->head;
    for(; current; current = current->next) {
        printf("[%d]->", current->key);
    }
    printf("\n");
}

// Since freeing the parent struct (the list itself) wont free all the nodes inside the list
// we want to make sure that we clean all that up as well to avoid memory leaks.
void freeList(List* list) {
    if(isEmpty(list)) {
        printf("Can't free an empty list.\n");
        return;
    }

    Node* current = list->head;
    Node* tmp = NULL;
    while(current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    // Now that all the nodes inside the list are freed up we can safely
    // free the memory of the list itself.
    free(list);
}