/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#include "main.h"

int main(int argc, char** argv){
    srand(time(NULL));

    string stringName = "TURTLE";
    Graph newGraph;

    cout << endl;
    cout << endl << endl; 
    for(int i = 0; i<=10; i++){
        if(newGraph.addVertex(i*2, &stringName)){
            cout << "added " << i*2 << ": " << stringName << endl;
        }
    }
    newGraph.depthFirstTraversal(9);
    cout << endl;

    stringName = "HARE";
    for(int i = 0; i<=25; i++){
        if(newGraph.addVertex(i, &stringName)){
            cout << "added " << i << ": " << stringName << endl;
        }
    }
    cout << endl;

    newGraph.depthFirstTraversal(9);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    cout << endl;

    newGraph.addEdge(1, 4, 10);
    newGraph.addEdge(1, 25, 88);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    newGraph.addEdge(1, 4, 10);
    for(int i = 1; i<=25; i++){
        cout << "creating edge between " << 1 << " and " << i+1 << "... ";
        if(newGraph.addEdge(1, i+1, i*2)){
            cout << "success" << endl;
        }else{
            cout << "failed" << endl;
        }
    }


    newGraph.depthFirstTraversal(9);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    return 0;
}