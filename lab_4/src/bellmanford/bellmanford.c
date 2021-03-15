#include <stdio.h>
#include <stdlib.h>
#include "bellmanford.h"

/**
 *
 * @param graph
 * @param source vertex
 */
void initializeSingleSource(Graph *graph, Node *source) {
    if (!graph || !source)
        return;

    Node *current = graph->edges->head;
    for(; current; current = current->next) {
        current->distance = 99999;
        current->pi = NULL;
    }
    source->distance = 0;
}

/**
 *
 * @param edge
 */
void relax(Node *edge) {
    if(edge->dest->distance > edge->src->distance + edge->weight) {
        edge->dest->distance = edge->src->distance + edge->weight;
        edge->src->pi = edge->dest;
    }
}

/**
 *
 * @param graph
 * @param weight
 * @param source node
 * @return
 */
int bellmanFord(Graph *graph, Node *source) {
    initializeSingleSource(graph, source);

    for(int i = 1; i < getNumVertices(graph) - 1; ++i) {
        Node *currentEdge = graph->edges->head;
        for(; currentEdge; currentEdge = currentEdge->next) {
            relax(currentEdge);
        }
    }

    Node *currentEdge = graph->edges->head;
    for(; currentEdge; currentEdge = currentEdge->next) {
        if(currentEdge->src->distance > currentEdge->dest->distance + currentEdge->weight) {
            return 0;
        }
    }
    return 1;
}