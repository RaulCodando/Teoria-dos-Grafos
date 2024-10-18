#ifndef UNIONFIND_HPP
#define UNIONFIND_HPP

#include <vector>

class UnionFind{

private:

    std::vector<int> rank;
    std::vector<int> parent;

public:

    UnionFind(int n);

    void makeSet(int x);

    int find(int x);

    void makeUnion(int x, int y); 

};

#endif //UNIONFIND_HPP