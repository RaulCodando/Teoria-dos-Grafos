#include "Graph.hpp"
#include <climits>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

vector<vector<int>> FloydWarshall(Graph g){
    vector<vector<int>> D = g.getW();
    int n = g.getN();

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(D[i][k] != INT_MAX && D[k][j] != INT_MAX)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    return D;
}

void help(){
    string texto = "Este programa terá como saída uma matriz contendo os comprimentos dos caminhos mínimos de cada vértice para cada vértice. Caso não haja caminho entre dois vértices quaisquer, será impresso N na respectiva posição da matriz.";

    cout << "-h : mostra o help" << endl;
    cout << "-o <arquivo> : redireciona asaida para o arquivo" << endl;
    cout << "-f <arquivo> : indica o arquivo que contém o grafo de entrada" << endl;
    cout << endl << texto << endl;
}

int main(int argc, char *argv[]){
    string inputFile;
    string outputFile;
    bool out = false;

    for(int i = 1; i < argc; i++){
        string arg = argv[i];

        if(arg == "-f" && i + 1 < argc){
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

    vector<vector<int>> output = FloydWarshall(g);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!out)
                if(output[i][j] != INT_MAX)
                    cout << output[i][j] << " ";
                else cout << "N" << " ";
            else
                if(output[i][j] != INT_MAX)
                    oFile << output[i][j] << " ";
                else oFile << "N" << " ";
        }

        if(!out)
            cout << "\n";
        else
            oFile << "\n";
    }

    if(out && oFile.is_open()) oFile.close();
    file.close();

    return 0;
}