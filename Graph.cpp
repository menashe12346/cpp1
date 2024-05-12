#include "Graph.hpp"

namespace ariel {

    // Constructor definition
    Graph::Graph() {}


    void Graph::loadGraph(const vector<vector<int>> &graph) {
    vector<int> tempVector;
    int i = 0, j = 0;
    // Check if the graph is a square matrix
    if (graph.size() != graph[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    this->matrix.clear(); // Clear the current matrix before loading the new one
    for (const auto &vector : graph) {
        tempVector.clear();
        for (const auto &element : vector) {
            if (i == j && element != 0) {
                throw std::invalid_argument("Invalid graph: cannot be edge between a vertex to itself.");
            }
            tempVector.push_back(element);
            j++;
        }
        this->matrix.push_back(tempVector);
        j = 0;
        i++;
    }
}

    void Graph::printGraph() {
        int size = this->matrix.size();
        int count = 0;
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                cout << this->matrix[i][j] << " "; // Print the element followed by a space
                if (this->matrix[i][j] != 0) {
                    count++;
                }
            }
            cout << endl; // Move to the next line after printing each row
        }
        cout << "Graph with " << size << " vertices and " << count << " edges." << endl;
    }

}
