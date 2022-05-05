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

void Graph::createVertex(DataVertex** vertexBox, int id, string* info){
    DataVertex* newVertex = new DataVertex;
    newVertex->data.id = id;
    newVertex->data.information = *info;
    newVertex->next = nullptr;
    *vertexBox = newVertex;
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
        DataVertex* testVertex3;
        if(!graphList[0]){
            createVertex(&testVertex3, id, info);
            graphList[0] = testVertex3;
            vertexCount++;
            added = true;
        }else if(graphList[0] && id > graphList[vertexCount-1]->data.id){
            createVertex(&testVertex3, id, info);
            graphList.push_back(testVertex3);
            vertexCount++;
            added = true;
        }else{
            int placeHolder = binarySearch(0, vertexCount-1, id);
            if(id != graphList[placeHolder]->data.id){
                createVertex(&testVertex3, id, info);
                if(id < graphList[placeHolder]->data.id){
                    graphList.insert(graphList.begin()+placeHolder, testVertex3);
                }else{
                    graphList.insert(graphList.begin()+placeHolder+1, testVertex3);
                }
                vertexCount++;
                added = true;
            }
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
        cout << graphList[i]->data.id << ": " << graphList[i]->data.information;
        current = graphList[i]->next;
        while(current){
            cout << " -> " << current->data.id << ": " << current->data.information;
            current = current->next;
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraversal(int startVertex){
    DataVertex* current; 
    for(int i=0; i<vertexCount; i++){
        cout << graphList[i]->data.id << ": " << graphList[i]->data.information;
        current = graphList[i]->next;
        while(current){
            cout << " -> " << current->data.id << ": " << current->data.information;
            current = current->next;
        }
        cout << endl;
    }
}

void Graph::clear(){

}