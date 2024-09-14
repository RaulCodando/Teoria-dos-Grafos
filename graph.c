#include "graph.h"

Graph *createGraph(int n){
    Graph *newGraph = (Graph*) malloc(sizeof(Graph));
    newGraph->adjList = (Node**) malloc(sizeof(Node*) * n);
    newGraph->visited = (short*) malloc(sizeof(short) * n);


    for(int i = 0; i < n; i++){
        newGraph->adjList[i] = createLinkedList();
        newGraph->visited[i] = -1;
    }

    return newGraph;
}

void addEdge(Graph *g, int v1, int v2){
    g->adjList[v1] = addNodeEnd(g->adjList[v1], v2);
    g->adjList[v2] = addNodeEnd(g->adjList[v2], v1);
}

void dfsRec(Graph *g, int v, int* cnt){
    g->visited[v] = (*cnt)++;

    Node *aux = g->adjList[v];

    while(aux != NULL){
        if(g->visited[aux->item] == -1) dfsRec(g, aux->item, cnt);
        aux = aux->next;
    }
}

void dfs(Graph *g, int n){
    int cnt = 0;

    for(int i = 0; i < n; i++){
        if(g->visited[i] == -1) {
            dfsRec(g, i, &cnt);
        }
    }
}

void clearGraph(Graph *g, int n){
    for(int i = 0; i < n; i++){
        clearList(g->adjList[i]);
    }

    free(g);
}
