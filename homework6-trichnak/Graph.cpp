#include "Graph.h"

template<class LabelType>
Graph<LabelType>::Graph(int size, vector<LabelType> vec) {
    numVertices = size;
    storage.resize(size);
    vertices.resize(size);
    for(int i = 0; i < size; i++) {
        storage[i].resize(size, -1);
        vertices[i] = vec[i];
    }
}

template<class LabelType>
int Graph<LabelType>::getNumVertices() {
    return numVertices;
}

template<class LabelType>
int Graph<LabelType>::getNumEdges() {
    int count;
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0; j < numVertices; j++) {
            if(storage[i][j] > 0) {
                count++;
            }
        }
    }
    return count;
}

template<class LabelType>
bool Graph<LabelType>::add(int start, int end, int edgeWeight) {
    if(start < numVertices && end < numVertices) {
        storage[start][end] = edgeWeight;
        storage[end][start] = edgeWeight;
        return true;
    }
    return false;
}

template<class LabelType>
bool Graph<LabelType>::remove(int start, int end) {
    if(start < numVertices && end < numVertices) {
        storage[start][end] = -1;
        storage[end][start] = -1;
        return true;
    }
    return false;
}

template<class LabelType>
int Graph<LabelType>::getEdgeWeight(int start, int end) {
    return storage[start][end];
}

template<class LabelType>
void Graph<LabelType>::depthFirstTraversal(int start, void visit(LabelType vertex)) {
    vector<bool> seen(numVertices, false);
    stack<string> stk;
  
    stk.push(vertices[start]);

    for (int i = 0; i < numVertices; i++) {
        seen[start] = true;  
        if (storage[start][i] > 0 && (!seen[i])) {
            stk.push(vertices[i]);
            start = i;
            i = -1;
            continue;
        } 
    }
    while(!stk.empty()) {
        visit(stk.top());
        stk.pop();
    }
}

template<class LabelType>
void Graph<LabelType>::breadthFirstTraversal(int start, void visit(LabelType vertex)) {
    vector<bool> seen(numVertices, false);
    queue<string> q;
  
    q.push(vertices[start]);

    for (int i = 0; i < numVertices; i++) {
        seen[start] = true;  
        if (storage[start][i] > 0 && (!seen[i])) {
            q.push(vertices[i]);
            start = i;
            i = -1;
            continue;
        } 
    }
    while(!q.empty()) {
        visit(q.front());
        q.pop();
    }
}