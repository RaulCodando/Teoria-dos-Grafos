#include "UnionFind.hpp"

UnionFind::UnionFind(int n){
    parent.resize(n);
    rank.resize(n);
}

void UnionFind::makeSet(int x){
    parent[x] = x;
    rank[x] = 0;
}

int UnionFind::find(int x){
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void UnionFind::makeUnion(int x, int y){
    if(rank[x] >= rank[y]){
        parent[y] = x;

        if(rank[x] == rank[y]) rank[x]++;
    }
    else parent[x] = y;
}