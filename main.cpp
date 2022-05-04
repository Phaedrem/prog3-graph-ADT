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
    newGraph.breadthFirstTraversal(9);
    cout << endl << endl; 
    newGraph.addVertex(221, &stringName);

    newGraph.depthFirstTraversal(9);

    return 0;
}