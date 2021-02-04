#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

int main(){
    List* list = initList();
    insert(list, 20);
    insert(list, 40);
    insert(list, 60);
    insert(list, 10);

    Node* test = search(list, 10);

    printf("Empty: %d\n", isEmpty(list));
    printf("Searched: %d\n", test->key);

    freeList(list);
    return 0;
}
