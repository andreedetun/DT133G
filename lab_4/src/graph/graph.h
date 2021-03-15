#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include "../list/list.h"

typedef struct graph_t {
    List *vertices;

    List *edges;
} Graph;

Graph *createGraph(int n);

int getNumVertices(Graph *graph);

int getNumEdges(Graph *graph);

void addDirectedEdge(Graph *graph, Node *v1, Node *v2, int weight);

void addUndirectedEdge(Graph *graph, Node *v1, Node *v2, int weight);

List *getInNeighbors(Graph *graph, Node *v);

List *getOutNeighbors(Graph *graph, Node *v);

List *getNeighbors(Graph *graph, Node *v);

int hasEdge(Graph *graph, Node *v1, Node *v2);

#endif //LAB4_GRAPH_H
