#include "Algorithms.hpp"

namespace ariel {
        bool Algorithms::isConnected(Graph &graph) {
        // Get the number of vertices in the graph
        size_t vertices = graph.matrix.size();

        // If the graph is empty, it's considered connected
        if (vertices == 0) {
            return true;
        }

        // Set to store visited vertices
        std::set<size_t> visited_vertices;

        // Stack for DFS traversal
        std::stack<size_t> stack;

        // Start DFS traversal from vertex 0
        stack.push(0);

        // Perform DFS traversal
        while (!stack.empty()) {
            size_t vertex = stack.top();
            stack.pop();

            // If the vertex has not been visited yet
            if (visited_vertices.find(vertex) == visited_vertices.end()) {
                // Mark the vertex as visited
                visited_vertices.insert(vertex);

                // Visit adjacent vertices
                for (size_t adj = 0; adj < vertices; adj++) {
                    if (graph.matrix[vertex][adj] != 0) {
                        stack.push(adj);
                    }
                }
            }
        }

        // Check if we visited all the vertices
        return visited_vertices.size() == vertices;
    }


    string Algorithms::shortestPath(Graph &graph, int s, int v) {
        size_t numOfVertices = graph.matrix.size();
        vector<int> dist(graph.matrix.size(), INT_MAX); // Initialize distances to infinity
        dist[static_cast<size_t>(s)] = 0; // Initialize distances of s to 0
        vector<size_t> pai(numOfVertices, static_cast<size_t>(-1));

        for (size_t i = 1; i <= numOfVertices - 1; i++) { // Relax n - 1 times
            for (size_t j = 0; j < numOfVertices; j++) {
                for (size_t k = 0; k < numOfVertices; k++) {
                    if (graph.matrix[j][k] != 0 && dist[j] != INT_MAX && dist[j] + graph.matrix[j][k] < dist[k]) {
                        dist[k] = dist[j] + graph.matrix[j][k];
                        pai[k] = j;
                    }
                }
            }
        }

        for (size_t i = 0; i < numOfVertices; i++) { // Check if there is negative cycles
            for (size_t j = 0; j < numOfVertices; j++) {
                if (graph.matrix[i][j] != 0 && dist[i] != INT_MAX && dist[i] + graph.matrix[i][j] < dist[j]) {
                    return "-1";
                }
            }
        }

        // Print the distances
        size_t i = static_cast<size_t>(v); // Start from destination
        string path = to_string(i);
        while (i != static_cast<size_t>(s) && pai[i] != static_cast<size_t>(-1)) { // Traverse back until source is reached
            path = to_string(pai[i]) + "->" + path;
            i = pai[i];
        }
        if (i != static_cast<size_t>(s)) // If source is not reached
            return "-1";
        else
            return path;
    }

string Algorithms::isContainsCycle(Graph &graph) {
    size_t vertices = graph.matrix.size();
    if (vertices == 0) {
        return "0"; // No vertices in an empty graph
    }

    vector<int> color(vertices, 0); // 0 for white, 1 for gray, 2 for black
    vector<int> parent(vertices, -1); // Store parent vertices
    bool cycleFound = false;

    // Perform DFS from each vertex
    for (size_t start = 0; start < vertices; ++start) {
        if (color[start] == 0) { // If vertex is not visited
            stack<size_t> dfsStack;
            dfsStack.push(start); // Start DFS from this vertex

            while (!dfsStack.empty()) {
                size_t u = dfsStack.top();
                dfsStack.pop();

                if (color[u] == 1) { // If vertex is currently being visited (gray)
                    // Cycle detected
                    cycleFound = true;
                    // Print the cycle
                    string cycle;
                    size_t current = u;
                    do {
                        cycle += to_string(current) + "->";
                        current = static_cast<size_t>(parent[current]);
                    } while (current != start);
                    cycle += to_string(start);
                    cout << start << "->" << cycle << endl;
                    break;
                }

                if (color[u] == 2) // If vertex is already visited (black), skip
                    continue;

                color[u] = 1; // Mark current vertex as gray

                // Explore neighbors of u
                for (size_t v = 0; v < vertices; ++v) {
                    if (graph.matrix[u][v] != 0) { // There's an edge from u to v
                        if (color[v] == 0) { // If v is white (not visited)
                            parent[v] = static_cast<int>(u); // Set parent of v as u
                            dfsStack.push(v);
                        }
                    }
                }
            }
        }

        if (cycleFound)
            break;
    }

    return cycleFound ? "1" : "0"; // Return 1 if cycle found, else 0
}


     string Algorithms::isBipartite(Graph &graph) {
        size_t vertices = graph.matrix.size();
        if (vertices == 0) {
            return "The graph is bipartite: A={}, B={}"; // empty graph is Bipartite
        }

        vector<int> color(vertices, -1); // Assign colors to vertices, -1 means not colored yet
        queue<size_t> queue;

        for (size_t start = 0; start < vertices; ++start) {
            if (color[start] != -1) {
                continue; // Vertex already colored
            }

            color[start] = 0; // Color the start vertex with 0 (first partition)
            queue.push(start);

            while (!queue.empty()) {
                size_t vertex = queue.front();
                queue.pop();

                for (size_t adj = 0; adj < vertices; ++adj) {
                    if (graph.matrix[vertex][adj] != 0) {
                        if (color[adj] == -1) {
                            color[adj] = 1 - color[vertex]; // Assign the opposite color to adjacent vertex
                            queue.push(adj);
                        } else if (color[adj] == color[vertex]) {
                            return "0"; // Graph is not bipartite
                        }
                    }
                }
            }
        }

        // Graph is bipartite, print partitions
        vector<size_t> partitionA, partitionB;
        for (size_t i = 0; i < vertices; ++i) {
            if (color[i] == 0) {
                partitionA.push_back(i);
            } else {
                partitionB.push_back(i);
            }
        }

        // Print partitions
        string output = "The graph is bipartite: A={";
        for (size_t i = 0; i < partitionA.size(); ++i) {
            output += to_string(partitionA[i]);
            if (i < partitionA.size() - 1) {
                output += ", ";
            }
        }
        output += "}, B={";
        for (size_t i = 0; i < partitionB.size(); ++i) {
            output += to_string(partitionB[i]);
            if (i < partitionB.size() - 1) {
                output += ", ";
            }
        }
        output += "}";
        return output;

    }

         string Algorithms::negativeCycle(Graph &graph) {
        size_t vertices = graph.matrix.size(); // Use size_t instead of int for vertices
        vector<int> distances(vertices, INT_MAX);
        vector<int> predecessors(vertices, -1); // Store predecessors

        distances[0] = 0;

        // Relax edges |V| - 1 times
        for (size_t i = 0; i < vertices - 1; ++i) {
            for (size_t u = 0; u < vertices; ++u) {
                for (size_t v = 0; v < vertices; ++v) {
                    if (graph.matrix[u][v] != 0 && distances[u] != INT_MAX && distances[u] + graph.matrix[u][v] < distances[v]) {
                        distances[v] = distances[u] + graph.matrix[u][v];
                        predecessors[v] = static_cast<int>(u); // Update predecessor
                    }
                }
            }
        }

        // Check for negative cycles
        for (size_t u = 0; u < vertices; ++u) {
            for (size_t v = 0; v < vertices; ++v) {
                if (graph.matrix[u][v] != 0 && distances[u] != INT_MAX && distances[u] + graph.matrix[u][v] < distances[v]) {
                    // Negative cycle detected
                    size_t vertexInCycle = u;
                    for (size_t i = 0; i < vertices; ++i) {
                        vertexInCycle = static_cast<size_t>(predecessors[vertexInCycle]);
                    }

                    // Trace back to construct the cycle
                    vector<size_t> cycle;
                    size_t current = vertexInCycle;
                    do {
                        cycle.push_back(current);
                        current = static_cast<size_t>(predecessors[current]);
                    } while (current != vertexInCycle);

                    // Construct the cycle string
                    string cycleString;
                    for (size_t i = cycle.size() - 1; i >= 0; --i) {
                        cycleString += to_string(cycle[i]) + " ";
                    }
                    cycleString += to_string(cycle[0]); // Close the cycle

                    return "Negative cycle detected: " + cycleString;
                }
            }
        }

        return "No negative cycle detected";

    }


}