#include <stdio.h>
#include <stdlib.h>
#include "../../src/graph/graph.h"
#include "../../src/bellmanford/bellmanford.h"

void shortestPath() {
    Graph *graph = createGraph(4);
    printList(graph->vertices);

    Node *zero = search(graph->vertices, 0);
    Node *one = search(graph->vertices, 1);
    Node *two = search(graph->vertices, 2);
    Node *three = search(graph->vertices, 3);

    addDirectedEdge(graph, zero, one, 1);
    addDirectedEdge(graph, zero, three, 3);
    addUndirectedEdge(graph, one, two, 2);
    addDirectedEdge(graph, two, three, 1);

    List *oneNeighbors = getNeighbors(graph, one);
    printf("1's neighbors: ");
    printList(oneNeighbors);

    List *twoInNeighbor = getInNeighbors(graph, two);
    printf("2's in neighbors: ");
    printList(twoInNeighbor);

    List *threeOutNeighbor = getOutNeighbors(graph, three);
    printf("3's out neighbors: ");
    printList(threeOutNeighbor);

    if(bellmanFord(graph, zero)) {
        Node *shortestPath = graph->edges->head;
        for(; shortestPath; shortestPath = shortestPath->next) {
            printf("src: %d, dest: %d, weight: %d, distance: %d\n", shortestPath->src->key, shortestPath->dest->key, shortestPath->weight, shortestPath->dest->distance);
        }
    } else {
        printf("Negative weight cycle found, exiting\n");
    }
}

void negativeCycle() {
    Graph *graph = createGraph(5);

    Node *first = search(graph->vertices, 1);
    Node *second = search(graph->vertices, 2);
    Node *third = search(graph->vertices, 3);
    Node *fourth = search(graph->vertices, 4);
    Node *fifth = search(graph->vertices, 5);

    addDirectedEdge(graph, first, second, -1);
    addDirectedEdge(graph, second, third, -1);
    addDirectedEdge(graph, third, first, -4);
    addDirectedEdge(graph, first, fourth, 3);
    addDirectedEdge(graph, fifth, second, 11);

    if(bellmanFord(graph, first)) {
        Node *shortestPath = graph->edges->head;
        for(; shortestPath; shortestPath = shortestPath->next) {
            printf("src: %d, dest: %d, weight: %d, distance: %d\n", shortestPath->src->key, shortestPath->dest->key, shortestPath->weight, shortestPath->src->distance);
        }
    } else {
        printf("Negative weight cycle found, exiting\n");
    }
}

int main() {
    shortestPath();
    printf("--------------------------------\n");
    negativeCycle();
    return 0;
}