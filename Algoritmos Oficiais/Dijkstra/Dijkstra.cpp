#include "Graph.hpp"
#include <climits>
#include <string>
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

vector<int> dijkstra(Graph g, int v0){
    int n = g.getN();
    using vertex = pair<int, int>;
    vector<vector<vertex>> adjList = g.getAdjList();
    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);
    priority_queue<vertex, vector<vertex>, greater<vertex>> h;

    dist[v0-1] = 0;

    h.push({0, v0-1});

    while(!h.empty()){
        vertex u = h.top();
        h.pop();

        for(auto v: adjList[u.second]){
            if(dist[v.second] > dist[u.second] + v.first){
                dist[v.second] = dist[u.second] + v.first;
                prev[v.second] = u.second;
                h.push(v);
            }
        }
    }

    return dist;
}

void help(){
    cout << "-h : mostra o help" << endl;
    cout << "-o <arquivo> : redireciona a saida para o arquivo" << endl;
    cout << "-f <arquivo> : indica o arquivo que contém o grafo de entrada" << endl;
    cout << "-i : vértice inicial" << endl;
}

int main(int argc, char *argv[]){
    int v0 = 1;
    string inputFile;
    string outputFile;
    bool out = false;

    for(int i = 1; i < argc; i++){
        string arg = argv[i];

        if(arg == "-i" && i + 1 < argc){
            v0 = stoi(argv[++i]);
        }
        else if(arg == "-f" && i + 1 < argc){
            inputFile = argv[++i];
        }
        else if(arg == "-h"){
            help();
            return 0;
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

    vector<int> output = dijkstra(g, v0);

    for(int i = 0; i < output.size(); i++){
        if(output[i] == INT_MAX) output[i] = -1;
        
        if(out){
            oFile << i+1 << ":" << output[i] << " ";
        }
        else{
            cout << i+1 << ":" << output[i] << " ";
        }
    }

    if(out && oFile.is_open()) oFile.close();
    file.close();

    return 0;
}
