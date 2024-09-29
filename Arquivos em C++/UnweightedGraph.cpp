#include "UnweightedGraph.h"
#include <iostream>
#include <queue>

UnweightedGraph::UnweightedGraph(int n, bool isDirected) : Graph(n, isDirected){
    adjList.resize(n);
}

void UnweightedGraph::addEdge(int v1, int v2){
    adjList[v1-1].push_back(v2-1);
    edges.push_back({v1, v2});

    if(!isDirected) adjList[v2-1].push_back(v1-1);
}

int UnweightedGraph::getN(){
    return visited.size();
}

std::vector<std::pair<int, int>> UnweightedGraph::getEdges(){
    return edges;
}

std::vector<std::vector<int>> UnweightedGraph::getAdjList(){
    return adjList;
}

void UnweightedGraph::dfsRec(int v, int &cnt){
    visited[v] = cnt++;

    std::cout << v+1 << std::endl;

    for(auto u : adjList[v]){
        if(visited[u] == -1) dfsRec(u, cnt);
    }
}

void UnweightedGraph::dfs(){
    int cnt = 0;

    std::fill(visited.begin(), visited.end(), -1);

    for(int i = 0; i < visited.size(); i++){
        if(visited[i] == -1) dfsRec(i, cnt);
    }
}

void UnweightedGraph::bfs(int v0){
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
            if(visited[u] == -1){
                visited[u] = cnt++;
                f.push(u);
            }
        }
    }
}
