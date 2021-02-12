#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"
#include "stack/stack.h"

int main(){
    List* list = createList();
    insert(list, 23);
    insert(list, 45);
    insert(list, 24);
    insert(list, 12);

    Node* searched = search(list, 45);
    Node* succ = predecessor(list, searched);

    printList(list);
    printf("%d\n", succ->key);

    return 0;
}