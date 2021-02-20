#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "list/list.h"
#include "sort/insertion/insertion.h"
#include "sort/merge/mergelist.h"

#include "load_files/load_file.h"

int main(int argc, char *argv[]) {

    const char *fName = argv[1];

    int *a = load_file(fName);

    int size = a[0];
    // insertionSort(a);
    List *list = createList();

    for (unsigned int i = 1; i <= size; i++) // note this loops from 1 <= i <= size
    {
        // printf("%d\n", a[i]);
        insert(list, a[i]);
    }

    list = mergeSortAscending(list);
    printList(list);
    return 0;
}