#ifndef UNWEIGHTEDGRAPH_H
#define UNWEIGHTEDGRAPH_H

#include "Graph.h"

class UnweightedGraph : public Graph{

private:

    std::vector<std::vector<int>> adjList;
    std::vector<std::pair<int, int>> edges;

public:

    UnweightedGraph(int n, bool isDirected);

    void addEdge(int v1, int v2);

    void dfsRec(int v, int &cnt) override;

    void dfs() override;

    void bfs(int v0) override;

};

#endif //UNWEIGHTEDGRAPH_H
