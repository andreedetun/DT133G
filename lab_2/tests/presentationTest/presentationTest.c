#include <stdlib.h>
#include <stdio.h>
#include "../../src/load_files/load_file.h"
#include "../../src/list/list.h"
#include "../../src/sort/insertion/insertion.h"
#include "../../src/sort/merge//mergelist.h"

void test1() {
    int *a = load_file("../test-problems/test-10-3-problem");
    int size = a[0];
    insertionSort(a);
    printf("Insertion sort test-10-3-problem: ");
    for (int i = 1; i <= size; i++) // note this loops from 1 <= i <= size
    {
        printf("%d ", a[i]);
    }
    printf("\n--------------------------------\n");
}

void test2() {
    int *a = load_file("../test-problems/test-10-5-problem");
    int size = a[0];
    printf("Mergesort test-10-5-problem in doubly linked list\n");

    List *list = createList();
    for (int i = 1; i <= size; i++) {
        insert(list, a[i]);
    }
    printf("Unsorted list: ");
    printList(list);
    printf("Sorting list in ascending order..\n");
    list = mergeSortAscending(list);
    printList(list);
    printf("--------------------------------\n");
    freeList(list);
}

void test3() {
    int *a = load_file("../test-problems/test-10-3-problem");
    int size = a[0];
    printf("Mergesort test-10-3-problem in doubly linked list\n");

    List *list = createList();
    for (int i = 1; i <= size; i++) {
        insert(list, a[i]);
    }
    printf("Unsorted list: ");
    printList(list);
    printf("Sorting list in descending order..\n");
    list = mergeSortDescending(list);
    printList(list);
    printf("--------------------------------\n");
    freeList(list);
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}