#include <stdlib.h>
#include <stdio.h>
#include "graph.h"


Graph *createGraph(int n) {
    if(n < 0) return NULL;

    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = createList();
    graph->edges = createList();

    for(int i = 1; i <= n; ++i) {
        insert(graph->vertices, i);
    }

    return graph;
}

int getNumVertices(Graph* graph) {
    // If the list of vertices is empty we obviously have 0 vertices.
    if(isEmpty(graph->vertices))
        return 0;

    // We can take advantage of the built in length of the list.
    return graph->vertices->length;
}

int getNumEdges(Graph *graph) {
    // If the list of edges is empty we obviously have 0 edges.
    if(isEmpty(graph->edges))
        return 0;

    // We can take advantage of the built in length of the list.
    return graph->edges->length;
}