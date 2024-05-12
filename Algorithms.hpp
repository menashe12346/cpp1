#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.hpp"
#include <stack>
#include <set>
#include <climits> //for bellmanford
#include <queue>

using namespace std;

namespace ariel {
    class Algorithms {
    public:
         static bool isConnected(Graph &graph);

        static string shortestPath(Graph &graph, int s, int v);

         static string isContainsCycle(Graph &graph);

         static string isBipartite(Graph &graph);

         static string negativeCycle(Graph &graph);

    };
}

#endif