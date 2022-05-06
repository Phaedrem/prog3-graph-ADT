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

bool Graph::createEdge(int vertex, int weight, int index){
    bool created = false;
    if(graphList[index]->edges.front().first == -1){
        graphList[index]->edges[0].first = vertex;
        graphList[index]->edges[0].second = weight;
    }else if(vertex > graphList[index]->edges.back().first){
        graphList[index]->edges.push_back(make_pair(vertex, weight));
    }else{
        int nestedIndex = binarySearch(0, graphList[index]->edges.size(), vertex);
        if(vertex != graphList[index]->edges[nestedIndex].first){
            if(vertex < graphList[index]->edges[nestedIndex].first){
                graphList[index]->edges.insert(graphList[index]->edges.begin()+nestedIndex, make_pair(vertex,weight));
            }else{
                graphList[index]->edges.insert(graphList[index]->edges.begin()+nestedIndex+1, make_pair(vertex,weight));
            }
        }
    }
    created = true;
    return created;
}

void Graph::depthFirstAssist(int startingIndex, vector<bool> &visited){
    visited[startingIndex] = true;
    cout << graphList[startingIndex]->data.id << " ";
    int edgeIndex;
    for(int i=0; i < graphList[startingIndex]->edges.size(); i++){
        edgeIndex = binarySearch(0,vertexCount-1, graphList[startingIndex]->edges[i].first);
        if(visited[edgeIndex] == false){
            depthFirstAssist(edgeIndex, visited);
        }
    }
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
    if(startVertex != endVertex && startVertex == graphList[firstIndex]->data.id && endVertex == graphList[secondIndex]->data.id){
        if(createEdge(endVertex, weight, firstIndex)){
            createEdge(startVertex, weight, secondIndex);
            edgeCount++;
            connected = true;
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
    int startIndex = binarySearch(0, vertexCount-1, startVertex);
    if(graphList[startIndex]){
        vector<bool> visited(vertexCount, false);
        for(int i=0; i<vertexCount; i++){
            if(visited[startIndex] == false){
                depthFirstAssist(startIndex, visited);
            }
            startIndex = (startIndex+1) % vertexCount;
        }
    }
    
}

void Graph::breadthFirstTraversal(int startVertex){
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

void Graph::clear(){

}