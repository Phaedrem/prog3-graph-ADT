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
    for (int i = 0; i < vertexCount; i++){
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

void Graph::createVertex(Vertex** vertexBox, int id, string* info){
    Vertex* newVertex = new Vertex;
    newVertex->data.id = id;
    newVertex->data.information = *info;
    newVertex->edges.push_back(make_pair(-1, -1));
    *vertexBox = newVertex;
}

/*********************************
PUBLIC
*********************************/


int Graph::getNumVertices(){
    return vertexCount;
}

int Graph::getNumEdges(){
    return edgeCount;
}

int Graph::getEdgeWeight(int startVertex, int endVertex){
    return 0;
}

bool Graph::addVertex(int id, string* info){
    bool added = false;
    if(id > 0 && *info != ""){
        Vertex* testVertex;
        if(!graphList[0]){
            createVertex(&testVertex, id, info);
            graphList[0] = testVertex;
            vertexCount++;
            added = true;
        }else if(graphList[0] && id > graphList[vertexCount-1]->data.id){
            createVertex(&testVertex, id, info);
            graphList.push_back(testVertex);
            vertexCount++;
            added = true;
        }else{
            int placeHolder = binarySearch(0, vertexCount-1, id);
            if(id != graphList[placeHolder]->data.id){
                createVertex(&testVertex, id, info);
                if(id < graphList[placeHolder]->data.id){
                    graphList.insert(graphList.begin()+placeHolder, testVertex);
                }else{
                    graphList.insert(graphList.begin()+placeHolder+1, testVertex);
                }
                vertexCount++;
                added = true;
            }
        }
    }
    return added;
}

bool Graph::addEdge(int startVertex, int endVertex, int weight){
    bool connected = false;
    int firstIndex = binarySearch(0, vertexCount-1, startVertex);
    int secondIndex = binarySearch(0,vertexCount-1, endVertex);
    if(startVertex == graphList[firstIndex]->data.id && endVertex == graphList[secondIndex]->data.id){
        pair <int, int> current;
        current.first = graphList[firstIndex]->edges.front().first;
        int i = 0;
        while(current.first != graphList[firstIndex]->edges.back().first && current.first != endVertex){
            current.first = graphList[firstIndex]->edges[i].first;
            i++;
        }
        if(current.first != endVertex){
            if(graphList[firstIndex]->edges.front().first == -1){
                graphList[firstIndex]->edges[0].first = endVertex;
                graphList[firstIndex]->edges[0].second = weight;
            }else{
                graphList[firstIndex]->edges.push_back(make_pair(endVertex, weight));
            }

        }
        current.first = graphList[secondIndex]->edges.front().first;
        i = 0;
        while(current.first != graphList[secondIndex]->edges.back().first && current.first != endVertex){
            current.first = graphList[secondIndex]->edges[i].first;
            i++;
        }
        if(current.first != startVertex){
            if(graphList[secondIndex]->edges.front().first == -1){
                graphList[secondIndex]->edges[0].first = startVertex;
                graphList[secondIndex]->edges[0].second = weight;
            }else{
                graphList[secondIndex]->edges.push_back(make_pair(startVertex, weight));
            }
        }
    }
    return connected;
}

bool Graph::removeVertex(int id){
    return true;
}

bool Graph::removeEdge(int startVertex, int endVertex){
    return true;
}

void Graph::depthFirstTraversal(int startVertex){ 
    for(int i=0; i<vertexCount; i++){
        cout << graphList[i]->data.id << ": " << graphList[i]->data.information;
        if(graphList[i]->edges.front().first > 0){
            int j = 0;
            while(j != graphList[i]->edges.size()){
                cout << " -> " << graphList[i]->edges[j].first << ": " << graphList[i]->edges[j].second;
                j++;
            }
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraversal(int startVertex){
    for(int i=0; i<vertexCount; i++){
        cout << graphList[i]->data.id << ": " << graphList[i]->data.information;
        cout << endl;
    }
}

void Graph::clear(){

}