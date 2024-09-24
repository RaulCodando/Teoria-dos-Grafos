#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Graph.h"
#include <tuple>

class WeightedGraph : public Graph{

private:

    std::vector<std::vector<std::pair<int, int>>> adjList;
    std::vector<std::tuple<int, int, int>> edges;

public:

    WeightedGraph(int n, bool isDirected);

    void addEdge(int v1, int v2, int weight);

    void dfsRec(int v, int &cnt) override;

    void dfs() override;

    void bfs(int v0) override;
};

#endif //WEIGHTEDGRAPH_H
