#include <stdio.h>
#include <stdlib.h>
#include "../../src/loadfiles/load_file.h"
#include "../../src/binarytree/binarytree.h"

void loadAndInsert(const char *filename) {
    Tree* tree = createTree();
    int *arr = load_file(filename);
    int size = arr[0];

    for(int i = 1; i <= size; ++i) {
        insert(tree, arr[i]);
    }

    inOrderTreeWalk(tree->root);
    printf("\n");
    printf("--------------------------------\n");
    destroyTree(tree->root);
}

int main(int argc, char* argv[]) {
    const char* fName = argv[1];
    loadAndInsert(fName);
    return 0;
}