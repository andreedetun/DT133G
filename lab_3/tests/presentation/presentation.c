#include <stdio.h>
#include <stdlib.h>
#include "../../src/loadfiles/load_file.h"
#include "../../src/binarytree/binarytree.h"

void presentation(const char *filename) {
    Tree* tree = createTree();
    int *arr = load_file(filename);
    int size = arr[0];

    for(int i = 1; i <= size; ++i) {
        insert(tree, arr[i]);
    }
    inOrderTreeWalk(tree->root);
    printf("\n");
    printf("--------------------------------\n");
    Node *searchNode = search(tree->root, 56);

    Node *pred = predecessor(searchNode);
    Node *succ = successor(searchNode);

    printf("Predecessor of 56: %d\n", pred->key);
    printf("Successor of 56: %d\n", succ->key);
    printf("--------------------------------\n");

    delete(tree, pred);
    delete(tree, succ);

    Node *pred2 = predecessor(search(tree->root, 56));
    Node *succ2 = successor(search(tree->root, 56));

    printf("Predecessor of 56: %d\n", pred2->key);
    printf("Successor of 56: %d\n", succ2->key);
    printf("--------------------------------\n");

    int treeSize = computeSize(tree->root);
    int treeDepth = computeDepth(tree->root);

    printf("Tree size: %d\n", treeSize);
    printf("Tree depth: %d\n", treeDepth);
    printf("--------------------------------\n");

    destroyTree(tree->root);
}

int main(int argc, char* argv[]) {
    const char* fName = argv[1];
    presentation(fName);
    return 0;
}