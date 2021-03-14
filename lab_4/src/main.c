#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "list/list.h"
#include "graph/graph.h"
#include "bellmanford/bellmanford.h"

int main() {
    Graph *g = createGraph(5);
    printList(g->vertices);

    Node *first = search(g->vertices, 1);
    Node *second = search(g->vertices, 1);
    Node *third = search(g->vertices, 3);
    Node *fourth = search(g->vertices, 4);
    Node *fifth = search(g->vertices, 5);

    addDirectedEdge(first, second, -1);
    addDirectedEdge(second, third, 1);
    addDirectedEdge(third, first, -4);
    addDirectedEdge(first, fourth, 3);
    addDirectedEdge(fifth, second, 1);

    if(bellmanFord(g, second) == 1) {
        printf("Success!\n");
    } else {
        printf("Fuck\n");
    }
    return 0;
}