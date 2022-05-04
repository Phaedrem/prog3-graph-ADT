/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include "data.h"

using std::cout;
using std::endl;
using std::vector;

class Graph{


public:
    Graph();
    ~Graph();

    int getNumVertices();
    int getNumEdges();
    int getEdgeWeight(int, int);
    bool addVertex(int, Data*);
    bool addEdge(int, int, int);
    bool removeVertex(int);
    bool removeEdge(int, int);
    void depthFirstTraversal(int);
    void breadthFirstTraversal(int);
    void clear();

private:

    int vertexCount;
    int edgeCount;
    vector<DataVertex*> graphList;
    int binarySearch(int);

};

#endif /* GRAPH_GRAPH_H */