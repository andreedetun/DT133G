#include <stdlib.h>
#include "mergelist.h"
#include "../../utils/utils.h"

Node *mergeAscending(Node *first, Node *second) {
    if(first == NULL) {
        return second;
    }

    if(second == NULL) {
        return first;
    }

    if(first->key <= second->key) {
        first->next = mergeAscending(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = mergeAscending(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

List *mergeSortAscending(List *list) {
    // If the list is empty or theres only one element in the list we can't sort it.
    if(isEmpty(list) || list->head->next == NULL) {
        return list;
    }

    List* secondSplit = split(list);

    list = mergeSortAscending(list);
    secondSplit = mergeSortAscending(secondSplit);

    // Create a new list and set the head to the sorted chain of nodes.
    List* ret = createList();
    ret->head = mergeAscending(list->head, secondSplit->head);

    return ret;
}

Node *mergeDescending(Node *first, Node *second) {
    if(first == NULL) {
        return second;
    }

    if(second == NULL) {
        return first;
    }

    if(first->key >= second->key) {
        first->next = mergeDescending(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = mergeDescending(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

List *mergeSortDescending(List *list) {
    // If the list is empty or theres only one element in the list we can't sort it.
    if(isEmpty(list) || list->head->next == NULL) {
        return list;
    }

    List* secondSplit = split(list);

    list = mergeSortDescending(list);
    secondSplit = mergeSortDescending(secondSplit);

    // Create a new list and set the head to the sorted chain of nodes.
    List* ret = createList();
    ret->head = mergeDescending(list->head, secondSplit->head);

    return ret;
}