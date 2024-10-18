#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <tuple>
#include <algorithm>

class Graph{

private:

    int n;
    int totalWeight;
    std::vector<std::tuple<int, int, int>> edges;

public:

    Graph(int n);

    void addEdge(int v1, int v2, int weight);

    int getN();

    const std::vector<std::tuple<int, int, int>> &getEdges() const;

    int getTotalWeight();

    void sortEdges();

};

#endif //GRAPH_HPP