#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace ariel {
    class Graph {
    public:
        vector<vector<int>> matrix;

        // Constructor
        Graph();

        // Function to load the graph
        void loadGraph(const vector<vector<int>> &graph);

        //Function to print the number of vertices and edges in the graph
        void printGraph();
    };
}

#endif
