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
#define PRIMER -1

class Graph{


public:
    Graph();
    ~Graph();

    bool edgeExist(int, int);
    bool vertexExist(int);
    bool getVertex(int, Data*);
    int getNumVertices();
    int getNumEdges();
    int getEdgeWeight(int, int);
    bool addVertex(int, string*);
    bool addEdge(int, int, int);
    bool removeVertex(int);
    bool removeEdge(int, int);
    void depthFirstTraversal(int);
    void breadthFirstTraversal(int);
    void printGraph();
    void clearGraph();
    void clearEdges();

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