#include <stdio.h>
#include <stdlib.h>
#include "../../src/binarytree/binarytree.h"

// This also tests search.
void testInsertAndDelete() {
    Tree *tree = createTree();
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 7);
    insert(tree, -1);
    insert(tree, 10);

    inOrderTreeWalk(tree->root);
    printf("\n");
    Node *nodeToDelete = search(tree->root, 7);
    delete(tree, nodeToDelete);
    inOrderTreeWalk(tree->root);
    printf("\n");
    printf("--------------------------------\n");

    destroyTree(tree->root);
}

void testMinMax() {
    Tree *tree = createTree();
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 66);
    insert(tree, -15);
    insert(tree, -25);

    Node *maximum = max(tree->root);
    Node *minimum = min(tree->root);
    printf("Max: %d\n", maximum->key);
    printf("Min: %d\n", minimum->key);
    printf("--------------------------------\n");
    destroyTree(tree->root);
}

void testSuccessorAndPredecessor() {
    Tree *tree = createTree();
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 66);
    insert(tree, -15);
    insert(tree, -25);

    Node *findSuccessor = search(tree->root, -25);
    Node *findPredecessor = search(tree->root, 6);

    Node *successorNode = successor(findSuccessor);
    Node *predecessorNode = predecessor(findPredecessor);

    inOrderTreeWalk(tree->root);
    printf("\n");
    printf("Successor of %d: %d\n", findSuccessor->key, successorNode->key);
    printf("Predecessor of %d: %d\n", findPredecessor->key, predecessorNode->key);
    printf("--------------------------------\n");

    destroyTree(tree->root);
}

void testDepthAndSize() {
    Tree *tree = createTree();
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 66);
    insert(tree, -15);
    insert(tree, -25);

    int size = computeSize(tree->root);
    int depth = computeDepth(tree->root);

    inOrderTreeWalk(tree->root);
    printf("\n");
    printf("Tree size: %d\n", size);
    printf("Tree maximum depth: %d\n", depth);
    printf("--------------------------------\n");

    destroyTree(tree->root);
}

void testPrintSorted() {
    Tree *tree = createTree();
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 66);
    insert(tree, -15);
    insert(tree, -25);

    printf("Tree printed in sorted order: ");
    inOrderTreeWalk(tree->root);
    printf("\n");
    printf("--------------------------------\n");
    destroyTree(tree->root);
}

int main() {
    testInsertAndDelete();
    testMinMax();
    testSuccessorAndPredecessor();
    testDepthAndSize();
    testPrintSorted();
    return 0;
}