#include "Graph.hpp"
#include <climits>
#include <string>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

typedef struct output{
    int cost;
    vector<pair<int, int>> edges;
}Output;

Output prim(Graph g, int v0){
    int n = g.getN();
    using vertex = pair<int, int>;

    vector<vector<vertex>> adjList = g.getAdjList();
    priority_queue<vertex, vector<vertex>, greater<vertex>> f;
    vector<int> parent(n, -1);
    vector<int> cost(n, INT_MAX);
    vector<bool> visited(n, false);

    cost[v0-1] = 0;
    f.push({0, v0-1});

    while(!f.empty()){
        vertex v = f.top();
        f.pop();

        visited[v.second] = true;

        for(auto u: adjList[v.second]){
            if(!visited[u.second] && u.first < cost[u.second]){
                parent[u.second] = v.second;
                cost[u.second] = u.first;
                f.push(u);
            }
        }
    }

    int sum = 0;
    vector<vertex> edges;

    for(int i = 1; i < n; i++){
        sum += cost[i];
        edges.push_back({parent[i]+1, i+1});
    }

    edges.shrink_to_fit();

    Output result;
    result.cost = sum;
    result.edges = edges;

    return result;
}

void help(){
    cout << "-h : mostra o help" << endl;
    cout << "-o <arquivo> : redireciona a saida para o -arquivo-" << endl;
    cout << "-f <arquivo> : indica o arquivo que contém o grafo de entrada" << endl;
    cout << "-s : mostra a solução" << endl;
    cout << "-i : vértice inicial (para o algoritmo de Prim)" << endl;
}

int main(int argc, char *argv[]){
    int v0;
    string inputFile;
    string outputFile;
    bool show = false;
    bool out = false;

    for(int i = 1; i < argc; i++){
        string arg = argv[i];

        if(arg == "-i" && i + 1 < argc){
            v0 = stoi(argv[++i]);
        }
        else if(arg == "-s"){
            show = true;
        }
        else if(arg == "-f" && i + 1 < argc){
            inputFile = argv[++i];
        }
        else if(arg == "-h"){
            help();
        }
        else if(arg == "-o" && i + 1 < argc){
            outputFile = argv[++i];
            out = true;
        }
        else{
            cerr << "Parâmetro desconhecido ou faltando argumento: " << arg << endl;
            return 1;
        }
    }

    ifstream file(inputFile);
    ofstream oFile(outputFile);

    if(!file.is_open()){
        cerr << "Erro: não foi possível abrir o arquivo " << inputFile << "!\n";
        return 1;
    }

    if(!oFile.is_open() && out){
        cerr << "Erro: não foi possível abrir o arquivo " << outputFile << "!\n";
        return 1;
    }

    int n, m;

    file >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int v1, v2, weight;

        file >> v1 >> v2 >> weight;

        g.addEdge(v1, v2, weight);
    }

    Output result = prim(g, v0);

    if(show){
        vector<pair<int, int>> edges = result.edges;

        for(int i = 0; i < edges.size(); i++){
            if(out){
                oFile << "(" << edges[i].first << "," << edges[i].second << ") ";
            }
            else{
                cout << "(" << edges[i].first << "," << edges[i].second << ") ";
            }
        }
    }
    else{
        if(out) oFile << result.cost;
        else cout << result.cost;
    }

    if(out && oFile.is_open()) oFile.close();
    file.close();

    return 0;
}
