#ifndef GRAPH
#define GRAPH

#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

template<class LabelType>
class Graph {
    int numVertices;
    vector<vector<int>> storage;
    vector<LabelType> vertices;
public:
    Graph(int size, vector<LabelType> vertices);
    int getNumVertices();
    int getNumEdges();
    bool add(int start, int end, int edgeWeight);
    bool remove(int start, int end);
    int getEdgeWeight(int start, int end);
    void depthFirstTraversal(int start, void visit(LabelType vertex));
    void breadthFirstTraversal(int start, void visit(LabelType vertex));
};
//#include "Graph.cpp"
#endif
