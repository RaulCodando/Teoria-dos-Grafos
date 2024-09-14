#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"

typedef struct graph{
    Node **adjList;
    short *visited;
}Graph;

Graph *createGraph(int n);

void addEdge(Graph *g, int v1, int v2);

void dfsRec(Graph *g, int v, int* cnt);

int dfs(Graph *g, int n);

void clearGraph(Graph *g, int n);

#endif //GRAPH_H
