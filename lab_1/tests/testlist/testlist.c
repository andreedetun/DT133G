#include <stdio.h>
#include <stdlib.h>
#include "../../src/list/list.h"

void test1(List *list) {
    Node *max = maximum(list);
    Node *min = minimum(list);

    printf("L1 max: %d\n", max->key);
    printf("L1 min: %d\n", min->key);
}

void test2(List *list) {
    Node *max = maximum(list);
    Node *min = minimum(list);

    printf("L2 max: %d\n", max->key);
    printf("L2 min: %d\n", min->key);
}

void test3(List *list) {
    Node *key5 = search(list, 5);
    if (key5 != NULL) {
        Node *nodeSuccessorL1 = successor(list, key5);
        Node *nodePredecessorL1 = predecessor(list, key5);

        if (nodeSuccessorL1 != NULL) {
            printf("L1 key = 5 nodes successor: %d\n", nodeSuccessorL1->key);
        } else {
            printf("Node '%d' might already be the maximum node\n", key5->key);
        }

        if (nodePredecessorL1 != NULL) {
            printf("L1 key = 5 nodes predecessor: %d\n", nodePredecessorL1->key);
        } else {
            printf("Node '%d' might already be the minimum node\n", key5->key);
        }
    }
}

void test4(List *list) {
    Node *key9 = search(list, 9);
    if (key9 != NULL) {
        Node *nodeSuccessorL2 = successor(list, key9);
        Node *nodePredecessorL2 = predecessor(list, key9);

        if (nodeSuccessorL2 != NULL) {
            printf("L2 key = 9 nodes successor: %d\n", nodeSuccessorL2->key);
        } else {
            printf("Node '%d' might already be the maximum node\n", key9->key);
        }

        if (nodePredecessorL2 != NULL) {
            printf("L2 key = 9 nodes predecessor: %d\n", nodePredecessorL2->key);
        } else {
            printf("Node '%d' might already be the minimum node\n", key9->key);
        }
    }
}

void test5(List *list1, List *list2) {
    Node *maxList1 = maximum(list1);
    Node *predecessorList2 = predecessor(list2, maxList1);

    if (predecessorList2 != NULL) {
        printf("Key of the predecessor in L2 of the maximum in L1: %d\n", predecessorList2->key);
    } else {
        printf("Node '%d' might already be the maximum node\n", maxList1->key);
    }
}

void test6(List *list1, List *list2) {
    Node *maxList2 = maximum(list2);
    Node *predecessorList1 = predecessor(list2, maxList2);

    if (predecessorList1 != NULL) {
        printf("Key of the predecessor in L1 of the maximum in L2: %d\n", predecessorList1->key);
    } else {
        printf("Node '%d' might already be the maximum node\n", maxList2->key);
    }
}

int main() {

    List *L1 = createList();
    insert(L1, 3);
    insert(L1, 1);
    insert(L1, 5);
    insert(L1, 10);
    insert(L1, 8);
    insert(L1, 7);

    List *L2 = createList();
    insert(L2, 5);
    insert(L2, 2);
    insert(L2, 9);
    insert(L2, 6);
    insert(L2, 1);
    insert(L2, 2);

    test1(L1);
    test2(L2);
    test3(L1);
    test4(L2);
    test5(L1, L2);
    test6(L1, L2);

    freeList(L1);
    freeList(L2);
    return 0;
}