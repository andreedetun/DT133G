#include <stdlib.h>
#include <stdio.h>
#include "../../src/load_files/load_file.h"
#include "../../src/list/list.h"
#include "../../src/sort/insertion/insertion.h"
#include "../../src/sort/merge//mergelist.h"

void test1() {
    List* L1 = createList(), *L2 = createList();
    insert(L1, 0);
    insert(L1, 1);
    insert(L1, 2);
    insert(L1, 0);
    insert(L1, 1);
    insert(L1, 0);

    insert(L2, 5);
    insert(L2, 1);
    insert(L2, 6);
    insert(L2, 0);
    insert(L2, 1);
    insert(L2, 0);

    printf("Unsorted Andre personal number: ");
    printList(L1);
    printf("Sorting Andre's personal number in ascending order..\n");
    L1 = mergeSortAscending(L1);
    printList(L1);
    printf("--------------------------------\n");

    printf("Unsorted Kevin personal number: ");
    printList(L2);
    printf("Sorting Kevin's personal number in ascending order..\n");
    L2 = mergeSortAscending(L2);
    printList(L2);
    printf("--------------------------------\n");


    freeList(L1);
    freeList(L2);
}

void test2() {
    List* L1 = createList(), *L2 = createList();
    insert(L1, 0);
    insert(L1, 1);
    insert(L1, 2);
    insert(L1, 0);
    insert(L1, 1);
    insert(L1, 0);

    insert(L2, 5);
    insert(L2, 1);
    insert(L2, 6);
    insert(L2, 0);
    insert(L2, 1);
    insert(L2, 0);

    printf("Unsorted Andre personal number: ");
    printList(L1);
    printf("Sorting Andre's personal number in descending order..\n");
    L1 = mergeSortDescending(L1);
    printList(L1);
    printf("--------------------------------\n");

    printf("Unsorted Kevin personal number: ");
    printList(L2);
    printf("Sorting Kevin's personal number in descending order..\n");
    L2 = mergeSortDescending(L2);
    printList(L2);
    printf("--------------------------------\n");


    freeList(L1);
    freeList(L2);
}
int main() {
    test1();
    test2();
    return 0;
}