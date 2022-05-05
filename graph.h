/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <utility>
#include "data.h"

using std::cout;
using std::endl;
using std::vector;
using std::make_pair;

class Graph{


public:
    Graph();
    ~Graph();

    int getNumVertices();
    int getNumEdges();
    int getEdgeWeight(int, int);
    bool addVertex(int, string*);
    bool addEdge(int, int, int);
    bool removeVertex(int);
    bool removeEdge(int, int);
    void depthFirstTraversal(int);
    void breadthFirstTraversal(int);
    void clear();

private:

    int vertexCount;
    int edgeCount;
    vector<Vertex*> graphList;
    int binarySearch(int, int, int);
    void createVertex(Vertex**, int, string*);

};

#endif /* GRAPH_GRAPH_H */