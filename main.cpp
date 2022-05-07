/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#include "main.h"

int main(int argc, char** argv){
    srand(time(NULL));
    Data emptyData;



    int ids1[TESTDATA1] = {(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN,(std::rand() % (MAX - MIN + 1)) +MIN}; 
    string strings1[TESTDATA1] = {"TURTLE", "CAT", "DOG", "SNAKE", "BADGER", "LION","TIGER","BEAR", "GRIFFON","RAVEN"};
    int testInt;
    int testInt2;
    int testInt3;
    int testInt4;
    int testWeight; 
    string testString;
    
    cout << endl << "Creating an empty Graph" << endl;
    Graph newGraph;
    cout << "Created, attempting to print using printGraph, depthFirstTraversal, breadthFirstTraversal" << endl << endl;
    newGraph.printGraph();
    newGraph.depthFirstTraversal(9);
    newGraph.depthFirstTraversal(9);
    cout << endl;
    cout << "==============================================" << endl;
    cout << "Exist / Get Methods on empty graph" << endl;
    cout << "==============================================" << endl;
    cout << "========== edgeExist ==========" << endl;
    for(int i=0; i < TESTDATA2; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testInt2 = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.edgeExist(testInt,testInt2)){
            cout << "An edge between " << testInt << " and " << testInt2 << " exists" << endl;
        }else{
            cout << "No edge exists between " << testInt << " and " << testInt2 << endl;
        }
    }
    cout << endl << "Testing with ID out of range" << endl;
    testInt = 0;
    if(newGraph.edgeExist(testInt,testInt2)){
        cout << "An edge between " << testInt << " and " << testInt2 << " exists" << endl;
    }else{
        cout << "No edge exists between " << testInt << " and " << testInt2 << endl;
    }

    cout << endl << "========== vertexExist ==========" << endl;
    cout << "======== Pre-created IDs ========" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.vertexExist(testInt)){
            cout << "The vertex " << testInt << " exists" << endl;
        }else{
            cout << "Vertex " << testInt << " doesn't exist" << endl;
        }
    }
    cout << endl << "=========== Random IDs ==========" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = (std::rand() % (MAX - MIN + 1)) +MIN;
        if(newGraph.vertexExist(testInt)){
            cout << "The vertex " << testInt << " exists" << endl;
        }else{
            cout << "Vertex " << testInt << " doesn't exist" << endl;
        }
    }

    for(int i=0; i < TESTDATA1; i++){
        testInt = (std::rand() % (MAX - MIN + 1)) +MIN;
        if(newGraph.vertexExist(testInt)){
            cout << "The vertex " << testInt << " exists" << endl;
        }else{
            cout << "Vertex " << testInt << " doesn't exist" << endl;
        }
    }

    cout << endl << "========== getVertex ==========" << endl;
    cout << "======== Pre-created IDs ========" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.getVertex(testInt, &emptyData)){
            cout << "Vertex " << testInt << " found " << emptyData.id << ": " << emptyData.information << endl;
        }else{
            cout << "Vertex " << testInt << " not found" << endl;
        }
    }
    

    cout << endl;
    newGraph.printGraph();
    cout << endl << "Trying depthFirstTraversal and breadthFirstTraversal to show no change, starting at " << testInt << endl << endl;
    cout << endl << "Depth First: ";
    newGraph.depthFirstTraversal(testInt);
    cout << "Breadth First: ";
    newGraph.breadthFirstTraversal(testInt);
    cout << endl;
    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl << endl;

    cout << "==============================================" << endl;
    cout << "Adding vertices" << endl;
    cout << "==============================================" << endl;
    for(int i = 0; i<TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testString = strings1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.addVertex(testInt, &testString)){
            cout << "added " << testInt << ": " << testString << endl;
        }else{
            cout << "Failed to add " << testInt << ": " << testString << endl;
        }
    }
    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;
    cout << endl << "Printing Graph" << endl;
    newGraph.printGraph();
    cout << endl;

    testString = "";
    cout << endl << "Testing an empty string" << endl;
    if(newGraph.addVertex(testInt, &testString)){
        cout << "added " << testInt << ": " << testString << endl;
    }else{
        cout << "Failed to add " << testInt << ": " << testString << endl;
    }
    cout << endl;


    testInt = 0;
    testString = strings1[0];
    cout << endl << "Testing an ID out of range" << endl;
    if(newGraph.addVertex(testInt, &testString)){
        cout << "added " << testInt << ": " << testString << endl;
    }else{
        cout << "Failed to add " << testInt << ": " << testString << endl;
    }
    cout << endl;
    cout << "==============================================" << endl;
    cout << "Adding more vertices" << endl;
    cout << "==============================================" << endl;
    for(int i = 0; i<TESTDATA2; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testString = strings1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.addVertex(testInt, &testString)){
            cout << "added " << testInt << ": " << testString << endl;
        }else{
            cout << "Failed to add " << testInt << ": " << testString << endl;
        }
    }
    cout << endl << "Printing Graph" << endl;
    newGraph.printGraph();
    testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;
    cout << endl << "Trying depthFirstTraversal and breadthFirstTraversal from Vertex " << testInt << endl;
    cout << endl << "Depth First: ";
    newGraph.depthFirstTraversal(testInt);
    cout << "Breadth First: ";
    newGraph.breadthFirstTraversal(testInt);
    cout << endl;
    cout << "==============================================" << endl;
    cout << "Adding edges" << endl;
    cout << "==============================================" << endl;

    for(int i = 0; i<TESTDATA2; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testInt2 = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testWeight = (std::rand() % (MAX - MIN + 1)) +MIN;
        if(newGraph.addEdge(testInt, testInt2, testWeight)){
            cout << "Added an edge between " << testInt << " and " << testInt2 << " with a weight of " << testWeight << endl;
            testInt3 = testInt;
            testInt4 = testInt2;
        }else{
            cout << "Failed to add an edge between " << testInt << " and " << testInt2 << endl;
        }
    }
    cout << endl << "Printing Graph" << endl;
    newGraph.printGraph();
    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl << endl;

    cout << "Attempting to add duplicate edge between " << testInt4 << " and " << testInt3 << endl;
    if(newGraph.addEdge(testInt4, testInt3, testWeight)){
        cout << "Added an edge between " << testInt4 << " and " << testInt3 << " with a weight of " << testWeight << endl;
    }else{
        cout << "Failed to add an edge between " << testInt4 << " and " << testInt3 << endl;
    }

    cout << endl << "Trying depthFirstTraversal and breadthFirstTraversal from Vertex " << testInt3 << endl << endl;
    cout << endl << "Depth First: ";
    newGraph.depthFirstTraversal(testInt3);
    cout << "Breadth First: ";
    newGraph.breadthFirstTraversal(testInt3);
    cout << endl;
    testInt = 0;
    cout << endl << "Trying depthFirstTraversal and breadthFirstTraversal on a vertex out of range " << endl << endl;
    cout << endl << "Depth First: ";
    newGraph.depthFirstTraversal(testInt);
    cout << "Breadth First: ";
    newGraph.breadthFirstTraversal(testInt);
    cout << endl;
    

    cout << "==============================================" << endl;
    cout << "Getting Weights" << endl;
    cout << "==============================================" << endl;
    for(int i=0; i<TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testInt2 = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testWeight = newGraph.getEdgeWeight(testInt,testInt2);
        if(testWeight > MIN){
            cout << "The edge weight between vertex " << testInt << " and " << testInt2 << " is " << testWeight << endl;
        }else{
            cout << "There is no edge between " << testInt << " and " << testInt2 << endl;
        }
    }
    
    cout << endl << "Testing an ID out of range" << endl;
    testInt = 0;
    testWeight = newGraph.getEdgeWeight(testInt,testInt2);
    if(testWeight > MIN){
            cout << "The edge weight between vertex " << testInt << " and " << testInt2 << " is " << testWeight << endl;
        }else{
            cout << "There is no edge between " << testInt << " and " << testInt2 << endl;
        }

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl << endl;
    cout << "==============================================" << endl;
    cout << "Testing Exist & Get Methods" << endl;
    cout << "==============================================" << endl;
    
    cout << "========== edgeExist ==========" << endl;
    for(int i=0; i < TESTDATA2; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testInt2 = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.edgeExist(testInt,testInt2)){
            cout << "An edge between " << testInt << " and " << testInt2 << " exists" << endl;
        }else{
            cout << "No edge exists between " << testInt << " and " << testInt2 << endl;
        }
    }
    cout << endl << "Testing with ID out of range" << endl;
    testInt = 0;
    if(newGraph.edgeExist(testInt,testInt2)){
        cout << "An edge between " << testInt << " and " << testInt2 << " exists" << endl;
    }else{
        cout << "No edge exists between " << testInt << " and " << testInt2 << endl;
    }

    cout << endl << "========== vertexExist ==========" << endl;
    cout << "======== Pre-created IDs ========" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.vertexExist(testInt)){
            cout << "The vertex " << testInt << " exists" << endl;
        }else{
            cout << "Vertex " << testInt << " doesn't exist" << endl;
        }
    }
    cout << endl << "=========== Random IDs ==========" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = (std::rand() % (MAX - MIN + 1)) +MIN;
        if(newGraph.vertexExist(testInt)){
            cout << "The vertex " << testInt << " exists" << endl;
        }else{
            cout << "Vertex " << testInt << " doesn't exist" << endl;
        }
    }

    for(int i=0; i < TESTDATA1; i++){
        testInt = (std::rand() % (MAX - MIN + 1)) +MIN;
        if(newGraph.vertexExist(testInt)){
            cout << "The vertex " << testInt << " exists" << endl;
        }else{
            cout << "Vertex " << testInt << " doesn't exist" << endl;
        }
    }

    cout << endl << "========== getVertex ==========" << endl;
    cout << "======= Pre-created IDs =======" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        if(newGraph.getVertex(testInt, &emptyData)){
            cout << "Vertex " << testInt << " found " << emptyData.id << ": " << emptyData.information << endl;
        }else{
            cout << "Vertex " << testInt << " not found" << endl;
        }
    }
    
    cout << "======== Random IDs ========" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = (std::rand() % (MAX - MIN + 1)) +MIN;
        if(newGraph.getVertex(testInt, &emptyData)){
            cout << "Vertex " << testInt << " found " << emptyData.id << ": " << emptyData.information << endl;
        }else{
            cout << "Vertex " << testInt << " not found" << endl;
        }
    }

    cout << endl << "Trying print and traversal methods to show no change, starting at " << testInt3 << endl << endl;
    newGraph.printGraph();
    cout << endl << "Depth First: ";
    newGraph.depthFirstTraversal(testInt3);
    cout << "Breadth First: ";
    newGraph.breadthFirstTraversal(testInt3);
    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl << endl;

    cout << "==============================================" << endl;
    cout << "Testing Remove Methods" << endl;
    cout << "==============================================" << endl;
    cout << "========== removeEdge ==========" << endl;
    cout << "Attemping to remove a guaranteed edge between " << testInt3 << " and " << testInt4 << endl;
    if(newGraph.removeEdge(testInt3, testInt4)){
        cout << "Edge Removed" << endl;
    }else{
        cout << "Failed to remove" << endl;
    }
    cout << endl << "Attemping to remove randomEdges" << endl;
    for(int i=0; i < TESTDATA1; i++){
        testInt = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        testInt2 = ids1[(std::rand() % ((TESTDATA1-1) - MIN + 1)) +MIN];
        cout << "Attempting to remove edge between " << testInt << " and " << testInt2 << endl;
        if(newGraph.removeEdge(testInt, testInt2)){
            cout << "Edge Removed" << endl;
        }else{
            cout << "Failed to remove" << endl;
        }
    }
    cout << endl;
    newGraph.printGraph();
    cout << endl;
    newGraph.depthFirstTraversal(testInt3);
    newGraph.breadthFirstTraversal(testInt3);
    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl << endl;

    /*cout << endl << endl <<"Removing vertex 3" << endl << endl;

    newGraph.removeVertex(3);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    newGraph.printGraph();

    cout << endl << endl;

    newGraph.depthFirstTraversal(7);
    newGraph.breadthFirstTraversal(7);
    cout << endl << "CLEARING" << endl;
    newGraph.clear();
    cout << endl << "CLEARED" << endl;
    newGraph.printGraph();
    newGraph.depthFirstTraversal(7);
    newGraph.breadthFirstTraversal(7);

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;

    newGraph.printGraph();

    cout << endl << "Current vertex count is " << newGraph.getNumVertices() << " and current edge count is " << newGraph.getNumEdges() << endl;*/

    return 0;
}