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
    vertexCount = STARTPOSITION;
    edgeCount = STARTPOSITION;
    graphList.assign(1, nullptr);
}

Graph::~Graph(){
    clear();
}


/*********************************
PRIVATE
*********************************/


int Graph::vertexBinarySearch(int beginning, int end, int id){
    int mid = PRIMER;
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

int Graph::edgeBinarySearch(int vertexIndex, int beginning, int end , int id){
    int mid = PRIMER;
    while(beginning <= end){
        mid = beginning+(end-beginning)/2;
        if(graphList[vertexIndex]->edges[mid].first < id){
            beginning = mid+1;
        }else if(graphList[vertexIndex]->edges[mid].first > id){
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
    newVertex->edges.push_back(make_pair(PRIMER, PRIMER));
    *vertexBox = newVertex;
}

bool Graph::createEdge(int vertex, int weight, int index){
    bool created = false;
    if(graphList[index]->edges.front().first == PRIMER){
        graphList[index]->edges[STARTPOSITION].first = vertex;
        graphList[index]->edges[STARTPOSITION].second = weight;
        created = true;
    }else if(vertex > graphList[index]->edges.back().first){
        graphList[index]->edges.push_back(make_pair(vertex, weight));
        created = true;
    }else{
        int nestedIndex = edgeBinarySearch(index, STARTPOSITION, graphList[index]->edges.size()-1, vertex);
        if(vertex != graphList[index]->edges[nestedIndex].first){
            if(vertex < graphList[index]->edges[nestedIndex].first){
                graphList[index]->edges.insert(graphList[index]->edges.begin()+nestedIndex, make_pair(vertex,weight));
                created = true;
            }else{
                graphList[index]->edges.insert(graphList[index]->edges.begin()+nestedIndex+1, make_pair(vertex,weight));
                created = true;
            }
        }
    }
    return created;
}

void Graph::depthFirstAssist(int startingIndex, vector<bool> &visited){
    visited[startingIndex] = true;
    cout << graphList[startingIndex]->data.id << ": " << graphList[startingIndex]->data.information << " ";
    int edgeIndex;
    for(int i=0; i < graphList[startingIndex]->edges.size(); i++){
        edgeIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, graphList[startingIndex]->edges[i].first);
        if(visited[edgeIndex] == false){
            depthFirstAssist(edgeIndex, visited);
        }
    }
}

void Graph::breadthFirstAssist(int startingIndex, vector<bool> &visited, std::list<int> &queue){
    visited[startingIndex] = true;
    cout << graphList[startingIndex]->data.id << ": " << graphList[startingIndex]->data.information << " ";
    for(int i=0; i < graphList[startingIndex]->edges.size(); i++){
        if(!visited[vertexBinarySearch(STARTPOSITION, vertexCount-1,graphList[startingIndex]->edges[i].first)]){
            queue.push_back(graphList[startingIndex]->edges[i].first);
        }
    }
    while(!queue.empty()){
        int nextIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, queue.front());
        queue.pop_front();
        if(!visited[nextIndex]){
            breadthFirstAssist(nextIndex, visited, queue);
        }
    }
}

/*********************************
PUBLIC
*********************************/

bool Graph::edgeExist(int firstVertex, int secondVertex){
    bool found = false;
    if(graphList.front()){
        int vertexIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, firstVertex);
        if(firstVertex == graphList[vertexIndex]->data.id){
            int edgeIndex = edgeBinarySearch(vertexIndex, STARTPOSITION, graphList[vertexIndex]->edges.size()-1, secondVertex);
            if(secondVertex == graphList[vertexIndex]->edges[edgeIndex].first){
                found = true; 
            }
        }
    }   
    return found;
}

bool Graph::vertexExist(int firstVertex){
    bool found = false;
    if(graphList.front()){
        int vertexIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, firstVertex);
        if(firstVertex == graphList[vertexIndex]->data.id){
            found = true; 
        }
    }
    
    return found;
}

bool Graph::getVertex(int vertexID, Data* dataBox){
    bool found = false;
    dataBox->id = PRIMER;
    dataBox->information = "";
    if(graphList.front()){
        int vertexIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, vertexID);
        if(vertexID == graphList[vertexIndex]->data.id){
            dataBox->id = graphList[vertexIndex]->data.id;
            dataBox->information = graphList[vertexIndex]->data.information;
            found = true;
        }
    }
    
    return found;
}

int Graph::getNumVertices(){
    return vertexCount;
}

int Graph::getNumEdges(){
    return edgeCount;
}

int Graph::getEdgeWeight(int startVertex, int endVertex){
    int weight = PRIMER;
    if(graphList.front()){
        int index = vertexBinarySearch(STARTPOSITION, vertexCount-1, startVertex);
        if(startVertex == graphList[index]->data.id){
            int edgeIndex = edgeBinarySearch(index, STARTPOSITION, graphList[index]->edges.size()-1, endVertex);
            if(endVertex == graphList[index]->edges[edgeIndex].first){
                weight = graphList[index]->edges[edgeIndex].second;
            }
        }
    }
    return weight;
}

bool Graph::addVertex(int id, string* info){
    bool added = false;
    if(id > 0 && *info != ""){
        Vertex* testVertex;
        if(!graphList[STARTPOSITION]){
            createVertex(&testVertex, id, info);
            graphList[STARTPOSITION] = testVertex;
            vertexCount++;
            added = true;
        }else if(graphList[STARTPOSITION] && id > graphList[vertexCount-1]->data.id){
            createVertex(&testVertex, id, info);
            graphList.push_back(testVertex);
            vertexCount++;
            added = true;
        }else{
            int placeHolder = vertexBinarySearch(STARTPOSITION, vertexCount-1, id);
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
    if(graphList.front()){
        int firstIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, startVertex);
        int secondIndex = vertexBinarySearch(STARTPOSITION,vertexCount-1, endVertex);
        if(startVertex != endVertex && startVertex == graphList[firstIndex]->data.id && endVertex == graphList[secondIndex]->data.id){
            if(createEdge(endVertex, weight, firstIndex)){
                createEdge(startVertex, weight, secondIndex);
                edgeCount++;
                connected = true;
            }    
        }
    }
    return connected;
}

bool Graph::removeVertex(int id){
    bool removed = false;
    if(graphList.front()){
        int idIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, id);
        if(id == graphList[idIndex]->data.id){
            while(graphList[idIndex]->edges.front().first > 0){
                cout << "removing edge between " << id << " and " << graphList[idIndex]->edges.front().first << endl;
                removeEdge(id, graphList[idIndex]->edges.front().first);
            }
            graphList.erase(graphList.begin()+idIndex);
            graphList.shrink_to_fit();
            vertexCount--;
            removed = true;
        }
    }
    return removed;
}

bool Graph::removeEdge(int startVertex, int endVertex){
    bool removed = false;
    if(graphList.front()){
        int firstVectorIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, startVertex);
        int secondVectorIndex = vertexBinarySearch(STARTPOSITION,vertexCount-1, endVertex);
        if(startVertex != endVertex && startVertex == graphList[firstVectorIndex]->data.id && endVertex == graphList[secondVectorIndex]->data.id){
            int firstEdgeIndex = edgeBinarySearch(firstVectorIndex, STARTPOSITION, graphList[firstVectorIndex]->edges.size()-1, endVertex);
            int secondEdgeIndex = edgeBinarySearch(secondVectorIndex, STARTPOSITION, graphList[secondVectorIndex]->edges.size()-1, startVertex);
            if(startVertex == graphList[secondVectorIndex]->edges[secondEdgeIndex].first && endVertex == graphList[firstVectorIndex]->edges[firstEdgeIndex].first){
                    graphList[firstVectorIndex]->edges.erase(graphList[firstVectorIndex]->edges.begin()+firstEdgeIndex);
                    graphList[secondVectorIndex]->edges.erase(graphList[secondVectorIndex]->edges.begin()+secondEdgeIndex);
                    if(graphList[firstVectorIndex]->edges.size() == STARTPOSITION){
                        graphList[firstVectorIndex]->edges.push_back(make_pair(PRIMER,PRIMER));
                    }
                    if(graphList[secondVectorIndex]->edges.size() == STARTPOSITION){
                        graphList[secondVectorIndex]->edges.push_back(make_pair(PRIMER,PRIMER));
                    }
                    edgeCount--;
                    removed = true;
            }  
        }
    }
    return removed;
}

void Graph::depthFirstTraversal(int startVertex){
    if(graphList.front()){
        int startIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, startVertex);
        if(startVertex == graphList[startIndex]->data.id){
            if(graphList[startIndex]->edges.front().first > STARTPOSITION){
                vector<bool> visited(vertexCount, false);
                depthFirstAssist(startIndex, visited);
            }else{
                cout << graphList[startIndex]->data.id << ": " << graphList[startIndex]->data.information << " ";
            }
            cout << endl;
        }else{
            cout << "Vertex " << startVertex << " doesn't exist in graph" << endl;
        }
    }else{
        cout << "LIST IS EMPTY" << endl;
    }
}

void Graph::breadthFirstTraversal(int startVertex){
    if(graphList.front()){
        int startIndex = vertexBinarySearch(STARTPOSITION, vertexCount-1, startVertex);
        if(startVertex == graphList[startIndex]->data.id){
            if(graphList[startIndex]->edges.front().first > STARTPOSITION){
                vector<bool> visited(vertexCount, false);
                std::list<int> queue;
                breadthFirstAssist(startIndex, visited, queue);
            }else{
                cout << graphList[startIndex]->data.id << ": " << graphList[startIndex]->data.information << " ";
            }
            cout << endl;
        }else{
            cout << "Vertex " << startVertex << " doesn't exist in graph" << endl;
        }
    }else{
        cout << "LIST IS EMPTY" << endl;
    }
}

void Graph::printGraph(){
    if(graphList.front()){
        for(int i=0; i<vertexCount; i++){
            cout << graphList[i]->data.id << ": " << graphList[i]->data.information;
            if(graphList[i]->edges.front().first > STARTPOSITION){
                int j = 0;
                while(j != graphList[i]->edges.size()){
                    cout << " -> " << graphList[i]->edges[j].first << ": " << graphList[i]->edges[j].second;
                    j++;
                }
            }
            cout << endl;
        }
    }else{
        cout << "LIST IS EMPTY" << endl;
    }
}

void Graph::clear(){
    for(int i=0; i<vertexCount; i++){
        delete graphList[i];
    }
    graphList.assign(1, nullptr);
    vertexCount = STARTPOSITION;
    edgeCount = STARTPOSITION;
}