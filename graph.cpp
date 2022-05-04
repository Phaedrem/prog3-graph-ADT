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
    for(int i=0; i<10; i++){
        DataVertex* newVertex = new DataVertex;
        graphList.push_back(newVertex);
        graphList[i]->data.id = (i+1)*2;
        graphList[i]->data.information = "RANDOM";
        graphList[i]->next = nullptr;
        vertexCount++;
    }
    DataVertex* testVertex1 = new DataVertex;
    testVertex1->data.id = 100;
    testVertex1->data.information = "MONKEY";
    testVertex1->next = nullptr;
    graphList[0]->next = testVertex1;
    edgeCount++;

    DataVertex* testVertex2 = new DataVertex;
    testVertex2->data.id = 88;
    testVertex2->data.information = "SNAKE";
    testVertex2->next = nullptr;
    graphList[0]->next->next = testVertex2;
    edgeCount++;
}

Graph::~Graph(){
    DataVertex* current;
    for (int i = 0; i < vertexCount; i++){
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


int Graph::binarySearch(int beginning, int end, int id){
    int mid = -1;
    while(beginning <= end){
        mid = beginning+(end-beginning)/2;
        if(graphList[mid]->data.id < id){
            beginning = mid+1;
        }else if(graphList[mid]->data.id > id){
            end = mid-1;
        }else{
            beginning = end+1;
        }
    }
    return mid;
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

bool Graph::addVertex(int id, string* info){
    bool added = false;
    if(id > 0 && *info != ""){
        int mid = (vertexCount-1)/2;
        int placeHolder = binarySearch(0, vertexCount-1, id);
        if(id != graphList[placeHolder]->data.id){
            DataVertex* testVertex3 = new DataVertex;
            testVertex3->data.id = id;
            testVertex3->data.information = *info;
            testVertex3->next = nullptr;
            if(id > graphList[mid-1]->data.id && id < graphList[mid]->data.id){
                placeHolder = placeHolder+1;
            }
            graphList.insert(graphList.begin()+placeHolder, testVertex3);
            vertexCount++;
            added = true;
        }
    }
    return added;
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
    for(int i=0; i<vertexCount; i++){
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
    for(int i=0; i<vertexCount; i++){
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