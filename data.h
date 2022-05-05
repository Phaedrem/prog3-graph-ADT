/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::pair;

struct Data {
    int id;
    string information;
};

struct Vertex{
    Data data;
    vector<pair<int,int>> edges;
};

#endif /* GRAPH_DATA_H */
