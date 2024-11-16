#include <iostream>
#include <fstream>
#include <string>
#include "UnionFind.hpp"
#include "Graph.hpp"

using namespace std;

Graph kruskal(Graph g){
    int n = g.getN();
    using edge = tuple<int, int, int>;
    vector<edge> edges = g.getEdges();
    UnionFind uf(n);
    Graph t(n);

    for(int i = 0; i < n; i++){
        uf.makeSet(i);
    }

    for(auto e: edges){
        int weight = get<0>(e);
        int u = get<1>(e);
        int v = get<2>(e);

        int compU = uf.find(u);
        int compV = uf.find(v);
        
        if(compU != compV){
            t.addEdge(u+1, v+1, weight);
            uf.makeUnion(compU, compV);
        }
    }

    return t;
}

void help(){
    cout << "-h : mostra o help" << endl;
    cout << "-o <arquivo> : redireciona a saida para o -arquivo-" << endl;
    cout << "-f <arquivo> : indica o arquivo que contém o grafo de entrada" << endl;
    cout << "-s : mostra a solução" << endl;
}

int main(int argc, char *argv[]){
    string inputFile;
    string outputFile;
    bool show = false;
    bool out = false;

    for(int i = 1; i < argc; i++){
        string arg = argv[i];

        if(arg == "-s"){
            show = true;
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

    g.sortEdges();
    Graph output = kruskal(g);

    if(show){
        vector<tuple<int, int, int>> edges = output.getEdges();

        for(int i = 0; i < edges.size(); i++){
            if(out){
                oFile << "(" << get<1>(edges[i]) + 1 << "," << get<2>(edges[i]) + 1 << ") ";
            }
            else{
                cout << "(" << get<1>(edges[i]) + 1 << "," << get<2>(edges[i]) + 1 << ") ";
            }
        }
    }
    else{
        if(out) oFile << output.getTotalWeight();
        else cout << output.getTotalWeight();
    }

    if(out && oFile.is_open()) oFile.close();
    file.close();

    return 0;
}
