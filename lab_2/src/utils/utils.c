#include <stdlib.h>
#include "utils.h"

void swap(int *a, int *b) {
    int temp = *b;

    *b = *a;
    *a = temp;
}

// Helper function to split a doubly linked list in half.
List* split(List* list) {
    Node* fast = list->head, *slow = list->head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    List* tmp = createList();
    tmp->head = slow->next;
    slow->next = NULL;

    return tmp;
}