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
#include <list>
#include "data.h"

using std::cout;
using std::endl;
using std::vector;
using std::make_pair;

#define STARTPOSITION 0

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
    void printGraph();

private:

    int vertexCount;
    int edgeCount;
    vector<Vertex*> graphList;
    int vertexBinarySearch(int, int, int);
    int edgeBinarySearch(int, int, int, int);
    void createVertex(Vertex**, int, string*);
    bool createEdge(int, int, int);
    void depthFirstAssist(int, vector<bool>&);
    void breadthFirstAssist(int, vector<bool>&, std::list<int>&);

};

#endif /* GRAPH_GRAPH_H */