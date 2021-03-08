#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include "../list/list.h"

typedef struct graph_t {
    List *vertices;
    List *edges;

    int numVertices;
} Graph;

Graph *createGraph(int n);

int getNumVertices(Graph *graph);

#endif //LAB4_GRAPH_H
