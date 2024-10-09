#include "Graph.hpp"

Graph::Graph(int n){
    this->n = n;
    adjList.resize(n);
}

void Graph::addEdge(int v1, int v2, int weight){
    adjList[v1-1].push_back({weight, v2-1});
    adjList[v2-1].push_back({weight, v1-1});
}

int Graph::getN(){
    return n;
}

std::vector<std::vector<std::pair<int, int>>> Graph::getAdjList(){
    return adjList;
}