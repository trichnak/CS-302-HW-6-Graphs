salesman: main.cpp Graph.o
	g++ main.cpp Graph.o -o salesman

Graph.o: Graph.h Graph.cpp
	g++ -c Graph.cpp

clean:
	rm *.o salesman