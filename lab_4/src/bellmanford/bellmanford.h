#ifndef LAB4_BELLMANFORD_H
#define LAB4_BELLMANFORD_H
#include "../graph/graph.h"
#include "../list/list.h"

void initializeSingleSource(Graph *graph, Node *source);

void relax(Node *u, Node *v);

int bellmanFord(Graph *graph, Node *source);
#endif //LAB4_BELLMANFORD_H
