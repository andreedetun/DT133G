// André Falk Edetun & Kevin Güvenal
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "list.h"

int isEmpty(List *list) {
    return list->head == NULL ? 1 : 0;
}

List *createList() {
    List *tmp = (List *) malloc(sizeof(List));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->length = 0;
    return tmp;
}

Node *createNode() {
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->edges = createList();
    tmp->pi = NULL;
    tmp->weight = 9999999;
    tmp->prev = NULL;
    tmp->next = NULL;
    tmp->key = 0;

    return tmp;
}

void insert(List *list, int key) {
    Node *newNode = createNode();
    newNode->key = key;

    if (isEmpty(list)) {
        list->tail = newNode;
        list->length++;
    } else {
        list->head->prev = newNode;
        list->length++;
    }

    newNode->next = list->head;
    newNode->prev = NULL;
    list->head = newNode;
}

// This insert function will be useful in stacks and queues.
void insertNode(List *list, Node *node) {
    if (isEmpty(list)) {
        list->tail = node;
        list->length++;
    } else {
        list->head->prev = node;
        list->length++;
    }

    node->next = list->head;
    node->prev = NULL;
    list->head = node;
}

// The unlink function is mainly written to be used inside the delete function.
// Consider not making it global.
void unlinkNode(List *list, Node *node) {
    if (isEmpty(list)) {
        printf("Can't unlink a node from an empty list.\n");
        return;
    }

    if (node == list->tail) {
        list->tail = node->prev;
    }

    if (node == list->head) {
        list->head = list->head->next;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
}

// The delete function requires a pointer to the node that should be deleted.
// We should consider making an override of the delete
// function if we wish to delete a node based on some other params, though the delete logic stays the same.
Node* delete(List *list, Node *node) {
    if (isEmpty(list)) {
        printf("Can't delete a node from an empty list.\n");
        return NULL;
    }

    if(node == NULL) {
        printf("Can't delete a node that doesn't exist\n");
        return NULL;
    }

    Node* tmp = node;
    unlinkNode(list, node);

    list->length--;

    // Make sure to free the memory of the node that has been unlinked.
    free(node);

    return tmp;
}

Node *search(List *list, int key) {
    if (isEmpty(list)) {
        printf("Can't search an empty list.\n");
        return NULL;
    }

    Node *current = list->head;
    for (; current; current = current->next) {
        if (current->key == key) {
            return current;
        }
    }
    return NULL;
}

Node *maximum(List *list) {
    if (isEmpty(list)) {
        printf("Can't find the maximum node of an empty list.\n");
        return NULL;
    }

    Node *current = list->head;
    Node *max = current;

    for (; current; current = current->next) {
        if (current->key > max->key) {
            max = current;
        }
    }
    return max;
}

Node *minimum(List *list) {
    if (isEmpty(list)) {
        printf("Can't find the minimum node of an empty list.\n");
        return NULL;
    }

    Node *current = list->head;
    Node *min = current;

    for (; current; current = current->next) {
        if (current->key < min->key) {
            min = current;
        }
    }
    return min;
}

Node *successor(List *list, Node *node) {
    if (isEmpty(list)) {
        printf("Can't find a successor of a node from an empty list.\n");
        return NULL;
    }

    Node *current = list->head;
    Node *max = maximum(list);
    Node *ret = NULL;

    if (current->next == NULL) {
        current = list->head;
    }

    // The maximum node wont have a successor so we need to return NULL in that case.
    if (node == max) {
        return NULL;
    }

    for (; current; current = current->next) {
        if (current->key > node->key) {
            if (ret == NULL || ret->key > current->key) {
                ret = current;
            }
        }
    }
    return ret;
}

Node *predecessor(List *list, Node *node) {
    if (isEmpty(list)) {
        printf("Can't find a predecessor of a node from an empty list.\n");
        return NULL;
    }

    Node *current = list->head;
    Node *min = minimum(list);
    Node *ret = NULL;

    if (current->next == NULL) {
        current = list->head;
    }

    // The maximum node wont have a successor so we need to return NULL in that case.
    if (node == min) {
        return NULL;
    }

    for (; current; current = current->next) {
        if (current->key < node->key) {
            if (ret == NULL || ret->key < current->key) {
                ret = current;
            }
        }
    }
    return ret;
}

void printList(List *list) {
    if (isEmpty(list)) {
        printf("Can't print an empty list.\n");
        return;
    }

    Node *current = list->head;
    for (; current; current = current->next) {
        printf("[%d]->", current->key);
    }
    printf("\n");
}

// Since freeing the parent struct (the list itself) wont free all the nodes inside the list
// we want to make sure that we clean all that up as well to avoid memory leaks.
void freeList(List *list) {
    if (isEmpty(list)) {
        printf("Can't free an empty list.\n");
        return;
    }

    Node *current = list->head;
    Node *tmp = NULL;
    while (current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    // Now that all the nodes inside the list are freed up we can safely
    // free the memory of the list itself.
    free(list);
}
