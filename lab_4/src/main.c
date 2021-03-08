#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"
#include "graph/graph.h"

int main() {
    Graph *g = createGraph(5);
    printList(g->vertices);

    printf("Number of vertices: %d\n", getNumVertices(g));
    return 0;
}