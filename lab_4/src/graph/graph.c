#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


Graph *createGraph(int n) {
    if(n < 0) return NULL;

    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = createList();
    graph->numVertices = n;

    for(int i = 1; i <= n; ++i) {
        insert(graph->vertices, i);
    }

    return graph;
}

int getNumVertices(Graph* graph) {
    return graph->numVertices;
}