/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#include "graph.h"

/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/


Graph::Graph(){
    vertexCount = 0;
    edgeCount = 0;
    graphList.assign(1, nullptr);
}

Graph::~Graph(){
    graphList.clear();
}


/*********************************
PRIVATE
*********************************/


int Graph::binarySearch(int id){
    return 0;
}


/*********************************
PUBLIC
*********************************/


int Graph::getNumVertices(){
    return 0;
}

int Graph::getNumEdges(){
    return 0;
}

int Graph::getEdgeWeight(int startVertex, int endVertex){
    return 0;
}

bool Graph::addVertex(int id, Data* info){
    return true;
}

bool Graph::addEdge(int startVertex, int endVertex, int weight){
    return true;
}

bool Graph::removeVertex(int id){
    return true;
}

bool Graph::removeEdge(int startVertex, int endVertex){
    return true;
}

void Graph::depthFirstTraversal(int startVertex){

}

void Graph::breadthFirstTraversal(int startVertex){
    
}

void Graph::clear(){

}