#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(int n, bool isDirected) : Graph(n, isDirected){
    adjList.resize(n);
}

void WeightedGraph::addEdge(int v1, int v2, int weight){
    adjList[v1-1].push_back({weight, v2-1});
    edges.push_back({weight, v1, v2});

    if(!isDirected) adjList[v2-1].push_back({weight, v1-1});
}

void WeightedGraph::addEdge(std::tuple<int, int, int> edge){
    edges.push_back(edge);
    int v1 = std::get<1>(edge);
    int v2 = std::get<2>(edge);
    int weight = std::get<0>(edge);

    adjList[v1-1].push_back({weight, v2-1});
    if(!isDirected) adjList[v2-1].push_back({weight, v1-1});
}

int WeightedGraph::getN(){
    return visited.size();
}

std::vector<std::tuple<int, int, int>> WeightedGraph::getEdges(){
    return edges;
}

std::vector<std::vector<std::pair<int, int>>> WeightedGraph::getAdjList(){
    return adjList;
}

void WeightedGraph::dfsRec(int v, int &cnt){
    visited[v] = cnt++;

    std::cout << v+1 << std::endl;

    for(auto u : adjList[v]){
        if(visited[u.second] == -1) dfsRec(u.second, cnt);
    }
}

void WeightedGraph::dfs(){
    int cnt = 0;

    std::fill(visited.begin(), visited.end(), -1);

    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == -1) dfsRec(i, cnt);
    }
}

void WeightedGraph::bfs(int v0){
    v0 -= 1;

    std::fill(visited.begin(), visited.end(), -1);

    std::queue<int> f;

    int cnt = 0;

    visited[v0] = cnt++;

    f.push(v0);

    while(!f.empty()){
        int v = f.front();
        f.pop();

        std::cout << v+1 << std::endl;

        for(auto u : adjList[v]){
            if(visited[u.second] == -1){
                visited[u.second] = cnt++;
                f.push(u.second);
            }
        }
    }
}
