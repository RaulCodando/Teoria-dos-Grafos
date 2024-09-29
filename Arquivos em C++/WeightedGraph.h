#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Graph.h"
#include <tuple>
#include <iostream>
#include <queue>

class WeightedGraph : public Graph{

private:

    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::vector<std::tuple<int, int, int>> edges;

public:

    WeightedGraph(int n, bool isDirected);

    void addEdge(int v1, int v2, int weight);

    void addEdge(std::tuple<int, int, int> edge);

    int getN();

    std::vector<std::tuple<int, int, int>> getEdges();
    
    std::vector<std::vector<std::pair<int, int>>> getAdjList();

    void dfsRec(int v, int &cnt) override;

    void dfs() override;

    void bfs(int v0) override;
};

#endif //WEIGHTEDGRAPH_H
