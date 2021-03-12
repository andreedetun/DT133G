#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include "../list/list.h"

typedef struct graph_t {
    List *vertices;

    // Cant be the same list, needs to keep track of connections
    // in like pairs <v1, v2>
    List *edges;
} Graph;

Graph *createGraph(int n);

int getNumVertices(Graph *graph);

int getNumEdges(Graph *graph);

#endif //LAB4_GRAPH_H
