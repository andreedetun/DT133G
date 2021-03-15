#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/**
 *
 * @param n amount of vertices in the new graph
 * @return a new graph object
 */
Graph *createGraph(int n) {
    if (n < 0)
        return NULL;

    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->vertices = createList();
    graph->edges = createList();

    for (int i = 0; i < n; ++i) {
        insert(graph->vertices, i);
    }
    return graph;
}

/**
 *
 * @param graph
 * @return number of vertices
 */
int getNumVertices(Graph *graph) {
    if (!graph)
        return 0;

    // If the list of vertices is empty we obviously have 0 vertices.
    if (isEmpty(graph->vertices))
        return 0;

    // We can take advantage of the built in length of the list.
    return graph->vertices->length;
}

/**
 *
 * @param graph
 * @return number of edges
 */
int getNumEdges(Graph *graph) {
    if (!graph)
        return 0;

    // If the list of vertices is empty we obviously have 0 vertices.
    if (isEmpty(graph->edges))
        return 0;

    // We can take advantage of the built in length of the list.
    return graph->edges->length;
}


/**
 *
 * @param graph
 * @param v1 source
 * @param v2 endpoint
 * @param weight
 */
void addDirectedEdge(Graph *graph, Node *v1, Node *v2, int weight) {
    if (!v1 || !v2)
        return;

    Node *newEdge = createNode();
    newEdge->src = v1;
    newEdge->dest = v2;
    newEdge->weight = weight;

    insertNode(graph->edges, newEdge);
}

/**
 *
 * @param graph
 * @param v1 source
 * @param v2 endpoint
 * @param weight
 */
void addUndirectedEdge(Graph *graph, Node *v1, Node *v2, int weight) {
    if (!v1 || !v2)
        return;

    Node *newEdge = createNode();
    newEdge->src = v1;
    newEdge->dest = v2;
    newEdge->weight = weight;

    Node *secondEdge = createNode();
    secondEdge->src = v2;
    secondEdge->dest = v1;
    secondEdge->weight = weight;

    insertNode(graph->edges, newEdge);
    insertNode(graph->edges, secondEdge);
}

/**
 *
 * @param graph
 * @param v
 * @return a list of all edges pointing TO v
 */
List *getInNeighbors(Graph *graph, Node *v) {
    if (!graph || !v)
        return NULL;

    List *neighborList = createList();
    Node *currentEdge = graph->edges->head;
    for(; currentEdge; currentEdge = currentEdge->next) {
        if(currentEdge->src != v && currentEdge->dest == v) {
            insert(neighborList, currentEdge->src->key);
        }
    }
    return neighborList;
}

/**
 *
 * @param graph
 * @param v
 * @return a list of all edges pointing FROM v
 */
List *getOutNeighbors(Graph *graph, Node *v) {
    if (!graph || !v)
        return NULL;

    List *neighborList = createList();
    Node *currentEdge = graph->edges->head;
    for(; currentEdge; currentEdge = currentEdge->next) {
        if(currentEdge->src == v && currentEdge->dest != v) {
            insert(neighborList, currentEdge->dest->key);
        }
    }
    return neighborList;
}

/**
 *
 * @param graph
 * @param v
 * @return a list of all connected edges to v
 */

List *getNeighbors(Graph *graph, Node *v) {
    if (!graph || !v)
        return NULL;

    List *out = getOutNeighbors(graph, v);
    List *in = getInNeighbors(graph, v);

    List *neighborList = createList();
    Node *currentOut = out->head;
    Node *currentIn = in->head;

    if (out) {
        for (; currentOut; currentOut = currentOut->next) {
            insert(neighborList, currentOut->key);
        }
    }

    if (in) {
        for (; currentIn; currentIn = currentIn->next) {
            insert(neighborList, currentIn->key);
        }
    }
    return neighborList;
}

/**
 *
 * @param v1 source
 * @param v2 endpoint
 * @return 1 if edge exists 0 if not
 */
int hasEdge(Graph *graph, Node *v1, Node *v2) {
    if (!v1 || !v2)
        return 0;

    Node *currentEdge = graph->edges->head;
    for(; currentEdge; currentEdge = currentEdge->next) {
        if((currentEdge->src == v1 && currentEdge->dest == v2) ||
                (currentEdge->src == v2 && currentEdge->dest == v1)) {
            return 1;
        }
    }
    return 0;
}