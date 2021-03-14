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

    Node *current = graph->vertices->head;

    for (; current; current = current->next) {
        current->distance = 9999999;
        current->pi = NULL;
    }
    source->distance = 0;
}

/**
 *
 * @param u vertex 1
 * @param v vertex 2
 * @param weight
 */
void relax(Node *u, Node *v) {
    if (!u || !v)
        return;

    if (v->distance > (u->distance + u->weight)) {
        v->distance = u->distance + u->weight;
        v->pi = u;
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

    for (int i = 0; i < (getNumVertices(graph) - 1); ++i) {
        Node *currentVertex = graph->vertices->head;
        for (; currentVertex; currentVertex = currentVertex->next) {
            Node *currentEdge = currentVertex->edges->head;
            for (; currentEdge; currentEdge = currentEdge->next) {
                relax(currentVertex, currentEdge);
            }
        }
    }

    Node *currentVertex = graph->vertices->head;
    for(; currentVertex; currentVertex = currentVertex->next) {
        Node *currentEdge = currentVertex->edges->head;
        for(; currentEdge; currentEdge = currentEdge->next) {
            if(currentEdge->distance > (currentEdge->distance + currentEdge->weight)) {
                return 0;
            }
        }
    }
    return 1;
}