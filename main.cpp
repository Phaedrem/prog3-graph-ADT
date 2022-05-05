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

    cout << endl;

    newGraph.addEdge(2, 6, 10);
    newGraph.addEdge(1, 25, 88);
    newGraph.addEdge(2, 6, 10);

    newGraph.depthFirstTraversal(9);

    return 0;
}