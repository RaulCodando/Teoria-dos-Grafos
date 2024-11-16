#include "Graph.hpp"
#include <climits>

Graph::Graph(int n){
    this->n = n;
    W.resize(n);

    for(int i = 0; i < n; i++){
        W[i].resize(n);

        std::fill(W[i].begin(), W[i].end(), INT_MAX);

        W[i][i] = 0;
    }
}

void Graph::addEdge(int v1, int v2, int weight){
    W[v1-1][v2-1] = weight;
}

const std::vector<std::vector<int>> &Graph::getW() const{
    return W;
}

int Graph::getN(){
    return n;
}