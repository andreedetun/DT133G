#include <stdio.h>
#include <stdlib.h>
#include "list/list.h"

int main(){
	// TEST
    List* list = initList();
    insert(list, 20);
    insert(list, 40);
    insert(list, 60);
    insert(list, 10);

    printf("Empty: %d", isEmpty(list));
    return 0;
}