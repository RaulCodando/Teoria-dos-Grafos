#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph{

private:

    int n;
    std::vector<std::vector<int>> W;

public:

    Graph(int n);

    void addEdge(int v1, int v2, int weight);

    const std::vector<std::vector<int>> &getW() const;

    int getN();

};

#endif //GRAPH_HPP