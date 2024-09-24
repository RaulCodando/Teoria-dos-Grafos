#include "Graph.h"

Graph::Graph(int n, bool isDirected) : isDirected(isDirected){
    Graph::visited.resize(n);
}
