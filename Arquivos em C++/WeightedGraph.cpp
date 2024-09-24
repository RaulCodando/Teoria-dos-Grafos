#include "WeightedGraph.h"
#include <iostream>
#include <queue>

WeightedGraph::WeightedGraph(int n, bool isDirected) : Graph(n, isDirected){
    adjList.resize(n);
}

void WeightedGraph::addEdge(int v1, int v2, int weight){
    adjList[v1].push_back({v2, weight});
    edges.push_back({v1, v2, weight});

    if(!isDirected) adjList[v2].push_back({v1, weight});
}

void WeightedGraph::dfsRec(int v, int &cnt){
    visited[v] = cnt++;

    std::cout << v << std::endl;

    for(auto u : adjList[v]){
        if(visited[u.first] == -1) dfsRec(u.first, cnt);
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
    std::fill(visited.begin(), visited.end(), -1);

    std::queue<int> f;

    int cnt = 0;

    visited[v0] = cnt++;

    f.push(v0);

    while(!f.empty()){
        int v = f.front();
        f.pop();

        std::cout << v << std::endl;

        for(auto u : adjList[v]){
            if(visited[u.first] == -1){
                visited[u.first] = cnt++;
                f.push(u.first);
            }
        }
    }
}
