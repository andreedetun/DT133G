#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/**
 *
 * @param n amount of vertices in the new graph
 * @return a new graph object
 */
Graph *createGraph(int n) {
    if(n < 0)
        return NULL;

    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = createList();

    for(int i = 1; i <= n; ++i) {
        insert(graph->vertices, i);
    }

    return graph;
}

/**
 *
 * @param graph
 * @return number of vertices
 */
int getNumVertices(Graph* graph) {
    if(!graph)
        return 0;

    // If the list of vertices is empty we obviously have 0 vertices.
    if(isEmpty(graph->vertices))
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
    if(!graph)
        return 0;

    Node *current = graph->vertices->head;
    int total = 0;
    for(; current; current = current->next) {
        total += current->edges->length;
    }
    return total;
}

/**
 *
 * @param v1 source node for the edge
 * @param v2 endpoint node for the edge
 */
void addDirectedEdge(Node *v1, Node *v2) {
    if(!v1 || !v2)
        return;

    insertNode(v1->edges, v2);
}

/**
 *
 * @param v1 source node for the edge
 * @param v2 endpoint node for the edge
 */
void addUndirectedEdge(Node *v1, Node *v2) {
    if(!v1 || !v2)
        return;

    insertNode(v1->edges, v2);
    insertNode(v2->edges, v1);
}

/**
 *
 * @param graph
 * @param v
 * @return a list of all edges pointing TO v
 */
List *getInNeighbors(Graph *graph, Node *v) {
    if(!graph || !v)
        return NULL;

    List *neighborList = createList();
    Node *currentVertex = graph->vertices->head;
    for(; currentVertex; currentVertex = currentVertex->next) {
        Node *currentEdge = currentVertex->edges->head;
        for(; currentEdge; currentEdge = currentEdge->next) {
            if(hasEdge(currentEdge, v)) {
                insertNode(neighborList, currentEdge);
            }
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
    if(!graph || !v)
        return NULL;

    List *neighborList = createList();
    Node *currentVertex = graph->vertices->head;
    for(; currentVertex; currentVertex = currentVertex->next) {
        Node *currentEdge = currentVertex->edges->head;
        for(; currentEdge; currentEdge = currentEdge->next) {
            if(hasEdge(currentEdge, v)) {
                insertNode(neighborList, v);
            }
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
    if(!graph || !v)
        return NULL;

    List *out = getOutNeighbors(graph, v);
    List *in = getInNeighbors(graph, v);

    List *neighborList = createList();
    Node *currentOut = out->head;
    Node *currentIn = in->head;

    if(out) {
        for(; currentOut; currentOut = currentOut->next) {
            insert(neighborList, currentOut->key);
        }
    }

    if(in) {
        for(; currentIn; currentIn = currentIn->next) {
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
int hasEdge(Node *v1, Node *v2) {
    if(!v1 || !v2)
        return 0;

    Node *current = v1->edges->head;
    for(; current; current = current->next) {
        if(current == v2)
            return 1;
    }
    return 0;
}