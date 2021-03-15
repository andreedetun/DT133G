#include <stdio.h>
#include <stdlib.h>
#include "../../src/graph/graph.h"

int main() {
    Graph *graph = createGraph(5);
    printList(graph->vertices);

    printf("Total vertices: %d\n", getNumVertices(graph));

    Node *first = search(graph->vertices, 1);
    Node *second = search(graph->vertices, 2);
    Node *third = search(graph->vertices, 3);
    Node *fourth = search(graph->vertices, 4);
    Node *fifth = search(graph->vertices, 5);

    addDirectedEdge(graph, first, second, 1);
    addDirectedEdge(graph, second, third, 1);
    addDirectedEdge(graph, third, first, 4);
    addDirectedEdge(graph, first, fourth, 3);
    addDirectedEdge(graph, fifth, second, 11);

    List *firstNeighbors = getNeighbors(graph, first);
    printf("--------------------------------\n");
    printList(firstNeighbors);

    List *secondInNeighbors = getInNeighbors(graph, first);
    printf("--------------------------------\n");
    printList(secondInNeighbors);

    List *thirdOutNeighbors = getOutNeighbors(graph, first);
    printf("--------------------------------\n");
    printList(thirdOutNeighbors);

    printf("--------------------------------\n");
    printf("First has an edge with third: %d\n", hasEdge(graph, third, first));

    printf("--------------------------------\n");
    printf("number of edges: %d\n", getNumEdges(graph));

    printf("--------------------------------\n");
    printList(graph->vertices);
    printf("--------------------------------\n");

    Node *currentEdge = graph->edges->head;
    for(; currentEdge; currentEdge = currentEdge->next) {
        printf("src: %d, dest: %d, weight: %d, distance: %d\n", currentEdge->src->key, currentEdge->dest->key, currentEdge->weight, currentEdge->dest->distance);
    }

    return 0;
}