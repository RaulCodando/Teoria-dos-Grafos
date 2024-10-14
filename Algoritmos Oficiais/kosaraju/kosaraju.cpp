#include "kosaraheader.hpp"
using namespace std;



int main(int argc, char *argv[]) {
    string inputFile, outputFile;
    bool show_help = false;

    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-h") {
            show_help = true;
        } else if (string(argv[i]) == "-o" && i + 1 < argc) {
            outputFile = argv[++i];
        } else if (string(argv[i]) == "-f" && i + 1 < argc) {
            inputFile = argv[++i];
        }
    }

    if (show_help) {
        showHelp();
        return 0;
    }

    istream *input = &cin;
    ifstream inputFileStream;
    if (!inputFile.empty()) {
        inputFileStream.open(inputFile);
        if (!inputFileStream) {
            cerr << "Error opening input file." << endl;
            return 1;
        }
        input = &inputFileStream;
    }

    ostream *output = &cout;
    ofstream outputFileStream;
    if (!outputFile.empty()) {
        outputFileStream.open(outputFile);
        if (!outputFileStream) {
            cerr << "Error opening output file." << endl;
            return 1;
        }
        output = &outputFileStream;
    }

    int size;
    *input >> size;
    vector<vertex> g(size);
    creategraph(g, *input);

    stack<int> PostOrder;
    reverseDFS(g, PostOrder);
    postDFS(g, PostOrder, *output);

    if (inputFileStream.is_open()) {
        inputFileStream.close();
    }
    if (outputFileStream.is_open()) {
        outputFileStream.close();
    }

    return 0;
}
