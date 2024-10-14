#include "kosaraheader.hpp"
using namespace std; // utilizado por conveniência aqui



void creategraph(vector<vertex> &g, istream &input) {
    int connections;
    input >> connections;

    for (int i = 0; i < connections; i++) {
        int from, to;
        input >> from >> to;
        g[from - 1].pointsto.push_back(to - 1);
        g[to - 1].ispointedby.push_back(from - 1);
    }
}


void reverseDFSrec(vector<vertex> &g, int i, int &cont, stack<int> &PostOrder) {
    g[i].visited = cont++;
    for (auto u : g[i].pointsto) { //talvez deva inverter com l54!
        if (g[u].visited == -1) {
            reverseDFSrec(g, u, cont, PostOrder);
        }
    }
    PostOrder.push(i);
}

void reverseDFS(vector<vertex> &g, stack<int> &PostOrder) {
    int cont = 0;
    for (int c = 0; c < g.size(); c++) {
        g[c].visited = -1;
    }
    for (int i = 0; i < g.size(); i++) {
        if (g[i].visited == -1) {
            reverseDFSrec(g, i, cont, PostOrder);
        }
    }
}

void postDFSrec(vector<vertex> &g, int i, int &cont, ostream &output) {
    g[i].visited = cont++;
    output << i + 1 << " ";
    for (auto u : g[i].ispointedby) { // talvez deva inverter com l31!
        if (g[u].visited == -1) {
            postDFSrec(g, u, cont, output);
        }
    }
}

void postDFS(vector<vertex> &g, stack<int> &PostOrder, ostream &output) {
    int cont = 0;
    for (int c = 0; c < g.size(); c++) {
        g[c].visited = -1;
    }
    while (!PostOrder.empty()) {
        int aux = PostOrder.top();
        PostOrder.pop();
        if (g[aux].visited == -1) {
            postDFSrec(g, aux, cont, output);
            output << endl;
        }
    }
}

void showHelp() {
    cout << "Uso: ./kosaraju.bin [-h] [-o output_file] [-f input_file]" << endl;
    cout << "  -h               Mostrar ajuda" << endl;
    cout << "  -o <file>        Redirecionar output para <file>" << endl;
    cout << "  -f <file>        Especificar arquivo de entrada em <file>" << endl;
}
