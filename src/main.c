#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"

int main(){
    /* Is this how you inst. the lists, to test for maximum,minimum and so on?
     * int L1[6] = {3, 1, 5, 10, 8, 7};
    int L2[6] = {5, 2, 9, 6, 1, 2}; (this is basically just to test githubs push for me)*/
    List* list = initList();
    insert(list, 20);
    insert(list, 40);
    insert(list, 1);
    insert(list, -12);
    insert(list, 60);
    insert(list, 10);

    printList(list);
    freeList(list);
    return 0;
}