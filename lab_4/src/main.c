#include <stdlib.h>
#include <stdio.h>
#include "list/list.h"
#include "graph/graph.h"

int main() {
    Graph *g = createGraph(5);
    printList(g->vertices);

    Node *v = search(g->vertices, 1);
    Node *u = search(g->vertices, 4);

    addUndirectedEdge(u, v);

    List *neighbors = getNeighbors(g, u);
    printList(neighbors);

    // printList(v->edges);
    // printList(u->edges);
//
    // printList(g->vertices);
    // printf("Number of vertices: %d\n", getNumVertices(g));
    return 0;
}