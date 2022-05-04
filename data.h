/*********************
Name: Darren Bowers
Final
Purpose: Creating a graph ADT
**********************/

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string information;
    int edgeWeight;
};

struct DataVertex {
    Data data;
    DataVertex *next;
};

#endif /* GRAPH_DATA_H */
