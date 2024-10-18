kruskal: kruskal.o Graph.o UnionFind.o
	g++ kruskal.o Graph.o UnionFind.o -o kruskal.bin

kruskal.o: Kruskal.cpp
	g++ -c Kruskal.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

UnionFind.o: UnionFind.cpp
	g++ -c UnionFind.cpp

clean:
	rm *.o kruskal.bin