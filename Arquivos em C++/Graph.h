#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cstdlib>

class Graph{

protected:

    std::vector<int> visited;
    bool isDirected;

public:

    Graph(int n, bool isDirected);

    virtual void dfsRec(int v, int &cnt) = 0;

    virtual void dfs() = 0;

    virtual void bfs(int v0) = 0;
};

#endif //GRAPH_H
