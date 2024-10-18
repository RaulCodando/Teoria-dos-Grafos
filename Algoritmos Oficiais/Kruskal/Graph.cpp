#include "Graph.hpp"

Graph::Graph(int n){
    this->n = n;
    totalWeight = 0;
}

void Graph::addEdge(int v1, int v2, int weight){
    edges.push_back({weight, v1-1, v2-1});
    totalWeight += weight;
}

int Graph::getN(){
    return n;
}

const std::vector<std::tuple<int, int, int>> &Graph::getEdges() const{
    return edges;
}

int Graph::getTotalWeight(){
    return totalWeight;
}

void Graph::sortEdges(){
    std::sort(edges.begin(), edges.end());
}