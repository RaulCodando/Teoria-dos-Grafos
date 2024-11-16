floyd-warshall: Floyd-Warshall.o Graph.o
	g++ Floyd-Warshall.o Graph.o -o floyd-warshall.bin

Floyd-Warshall.o: Floyd-Warshall.cpp
	g++ -c Floyd-Warshall.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

clean:
	rm *.o floyd-warshall.bin
