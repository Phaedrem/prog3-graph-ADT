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
    newGraph.breadthFirstTraversal(9);
    newGraph.depthFirstTraversal(9);
    for(int i = 0; i<=5; i++){
        if(newGraph.addVertex(i*2, &stringName)){
            cout << "added " << i*2 << ": " << stringName << endl;
        }
    }
    newGraph.breadthFirstTraversal(9);
    cout << endl;

    stringName = "HARE";
    for(int i = 0; i<=10; i++){
        if(newGraph.addVertex(i, &stringName)){
            cout << "added " << i << ": " << stringName << endl;
        }
    }
    cout << endl;

    newGraph.depthFirstTraversal(7);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    cout << endl;

    newGraph.addEdge(7, 1, 10);
    newGraph.addEdge(7, 2, 88);
    newGraph.addEdge(1, 6, 88);
    newGraph.addEdge(6, 8, 88);
    newGraph.addEdge(6, 9, 88);
    newGraph.addEdge(10, 2, 88);
    newGraph.addEdge(2, 5, 88);
    newGraph.addEdge(3, 5, 88);
    newGraph.addEdge(3, 4, 88);
    newGraph.addEdge(4, 10, 88);

    newGraph.breadthFirstTraversal(7);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl << endl;

    if(newGraph.getEdgeWeight(7,1)){
        cout << "the edge weight between vertex 7 & 1 is " << newGraph.getEdgeWeight(7,1) << endl;
    }else{
        cout << "there is no edge between 7 & 1" << endl;
    }
    
    cout << endl;

    newGraph.breadthFirstTraversal(7);

    newGraph.depthFirstTraversal(7);

    cout << endl << endl;

    cout << "Removing edge between 2 and 10" << endl;
    newGraph.removeEdge(2, 10);

    cout << "Removing edge between 4 and 3" << endl;
    newGraph.removeEdge(4, 3);


    newGraph.breadthFirstTraversal(9);

    cout << endl;

    newGraph.depthFirstTraversal(9);

    cout << endl << endl <<"Removing vertex 3" << endl << endl;

    newGraph.removeVertex(3);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    newGraph.breadthFirstTraversal(7);

    cout << endl << endl;

    newGraph.depthFirstTraversal(7);
    cout << endl << "CLEARING" << endl;
    newGraph.clear();
    cout << endl << "CLEARED" << endl;
    newGraph.breadthFirstTraversal(7);

    newGraph.depthFirstTraversal(7);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    for(int i = 0; i<=5; i++){
        if(newGraph.addVertex(i*2, &stringName)){
            cout << "added " << i*2 << ": " << stringName << endl;
        }
    }

    newGraph.breadthFirstTraversal(7);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    return 0;
}