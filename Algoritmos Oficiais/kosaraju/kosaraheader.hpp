#include <climits>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std; // utilizado por conveniência aqui

struct vertex {
    vector<int> pointsto; // pointsto -> o vértice x aponta para os vértices contidos em pointsto
    vector<int> ispointedby; // ispointedby -> o vértice x é apontado pelos vértices contidos em ispointedby
    int visited;
};

void creategraph(vector<vertex> &g, istream &input);


void reverseDFSrec(vector<vertex> &g, int i, int &cont, stack<int> &PostOrder);

void reverseDFS(vector<vertex> &g, stack<int> &PostOrder);

void postDFSrec(vector<vertex> &g, int i, int &cont, ostream &output);

void postDFS(vector<vertex> &g, stack<int> &PostOrder, ostream &output);

void showHelp();
