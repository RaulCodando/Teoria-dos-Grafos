prim: prim.o Graph.o
	g++ prim.o Graph.o -o prim

prim.o: prim.cpp
	g++ -c prim.cpp

Graph.o: Graph.cpp
	g++ -c Graph.cpp

clean:
	rm *.o prim