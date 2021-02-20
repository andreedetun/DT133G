#include <stdlib.h>
#include <stdio.h>
#include "../../src/load_files/load_file.h"
#include "../../src/list/list.h"
#include "../../src/sort/insertion/insertion.h"
#include "../../src/sort/merge//mergelist.h"

void test1() {
    List *L1 = createList(), *L2 = createList();
    insert(L1, 3);
    insert(L1, 1);
    insert(L1, 5);
    insert(L1, 10);
    insert(L1, 8);
    insert(L1, 7);

    insert(L2, 5);
    insert(L2, 2);
    insert(L2, 9);
    insert(L2, 6);
    insert(L2, 1);
    insert(L2, 2);

    printf("Unsorted L1: ");
    printList(L1);
    printf("Sorting L1 in ascending order..\n");
    L1 = mergeSortAscending(L1);
    printList(L1);
    printf("--------------------------------\n");

    printf("Unsorted L2: ");
    printList(L2);
    printf("Sorting L2 in ascending order..\n");
    L2 = mergeSortAscending(L2);
    printList(L2);
    printf("--------------------------------\n");

    freeList(L1);
    freeList(L2);
}

void test2() {
    List *L1 = createList(), *L2 = createList();
    insert(L1, 3);
    insert(L1, 1);
    insert(L1, 5);
    insert(L1, 10);
    insert(L1, 8);
    insert(L1, 7);

    insert(L2, 5);
    insert(L2, 2);
    insert(L2, 9);
    insert(L2, 6);
    insert(L2, 1);
    insert(L2, 2);

    printf("Unsorted L1: ");
    printList(L1);
    printf("Sorting L1 in descending order..\n");
    L1 = mergeSortDescending(L1);
    printList(L1);
    printf("--------------------------------\n");

    printf("Unsorted L2: ");
    printList(L2);
    printf("Sorting L2 in descending order..\n");
    L2 = mergeSortDescending(L2);
    printList(L2);
    printf("--------------------------------\n");

    freeList(L1);
    freeList(L2);
}

int main(int argc, char *argv[]) {
    test1();
    test2();
    return 0;
}