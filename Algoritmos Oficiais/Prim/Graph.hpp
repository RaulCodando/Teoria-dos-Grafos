#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph{

private:

    int n;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:

    Graph(int n);

    void addEdge(int v1, int v2, int weight);

    int getN();

    std::vector<std::vector<std::pair<int, int>>> getAdjList();

};

#endif //GRAPH_HPP