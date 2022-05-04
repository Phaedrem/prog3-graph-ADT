/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#include "graph.h"

/*********************************
CONSTRUCTORS / DESTRUCTORS
*********************************/


/*Graph::Graph(){
    vertexCount = 0;
    edgeCount = 0;
    graphList.assign(1, nullptr);
}*/

Graph::Graph(){
    vertexCount = 0;
    edgeCount = 0;
    for(int i=0; i<5; i++){
        DataVertex* newVertex = new DataVertex;
        graphList.push_back(newVertex);
        graphList[i]->data.id = i;
        graphList[i]->data.information = "RANDOM";
        graphList[i]->next = nullptr;
    }
    DataVertex* testVertex1 = new DataVertex;
    testVertex1->data.id = 100;
    testVertex1->data.information = "MONKEY";
    testVertex1->next = nullptr;
    graphList[0]->next = testVertex1;

    DataVertex* testVertex2 = new DataVertex;
    testVertex2->data.id = 88;
    testVertex2->data.information = "SNAKE";
    testVertex2->data.edgeWeight = 8;
    testVertex2->next = nullptr;
    graphList[0]->next->next = testVertex2;
}

Graph::~Graph(){
    DataVertex* current;
    for (int i = 0; i < 5; i++){
        current = graphList[i]->next;
        while(current){
            graphList[i]->next = current->next;
            delete current;
            current = graphList[i]->next;
        }
        delete graphList[i];
    }
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
    DataVertex* current; 
    for(int i=0; i<5; i++){
        cout << "vertex " << graphList[i]->data.id << " contains: " << graphList[i]->data.information << endl;
        current = graphList[i]->next;
        while(current){
            cout << "It is connected to vertex " << current->data.id << " which contains: " << current->data.information << endl;
            current = current->next;
        }
    }
}

void Graph::breadthFirstTraversal(int startVertex){
    DataVertex* current; 
    for(int i=0; i<5; i++){
        cout << "vertex " << graphList[i]->data.id << " contains: " << graphList[i]->data.information << endl;
        current = graphList[i]->next;
        while(current){
            cout << "It is connected to vertex " << current->data.id << " which contains: " << current->data.information << endl;
            current = current->next;
        }
    }
}

void Graph::clear(){

}