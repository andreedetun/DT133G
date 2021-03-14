#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include "../list/list.h"

typedef struct graph_t {
    List *vertices;
} Graph;

Graph *createGraph(int n);

int getNumVertices(Graph *graph);

int getNumEdges(Graph *graph);

void addDirectedEdge(Node *v1, Node *v2);

void addUndirectedEdge(Node *v1, Node *v2);

List *getInNeighbors(Graph *graph, Node *v);

List *getOutNeighbors(Graph *graph, Node *v);

List *getNeighbors(Graph *graph, Node *v);

int hasEdge(Node *v1, Node *v2);

#endif //LAB4_GRAPH_H
