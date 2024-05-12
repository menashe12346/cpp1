### Introduction

The Graph Operations Library focuses on providing capabilities for working with graphs, including loading, printing, and performing various algorithms on graphs.

### Installation

To use this library, include the provided header files (`Graph.hpp` and `Algorithms.hpp`) in your C++ project.

```cpp
#include "Graph.hpp"
#include "Algorithms.hpp"
```

### Usage

Here's a brief overview of how to use the library:

1. **Loading a Graph**: Use the `loadGraph` function of the `Graph` class to load a graph.

    ```cpp
    ariel::Graph graph;
    graph.loadGraph(/* Your graph data */);
    ```

2. **Printing a Graph**: After loading a graph, you can print it using the `printGraph` function.

    ```cpp
    graph.printGraph();
    ```

3. **Performing Algorithms**: Utilize the functions provided by the `Algorithms` class to perform various graph algorithms.

    ```cpp
    ariel::Algorithms::isConnected(graph);
    ariel::Algorithms::shortestPath(graph, source, destination);
    ariel::Algorithms::isContainsCycle(graph);
    ariel::Algorithms::isBipartite(graph);
    ariel::Algorithms::negativeCycle(graph);
    ```

### Graph Class

The `Graph` class provides functionality for representing and working with graphs. It includes methods for loading and printing graphs.

### Algorithms Class

The `Algorithms` class contains static methods for performing various graph algorithms, including:

- Connectivity checks (`isConnected`)
- Shortest path finding (`shortestPath`)
- Cycle detection (`isContainsCycle`)
- Bipartiteness check (`isBipartite`)
- Negative cycle detection (`negativeCycle`)

### Implementation Details

The `Graph.cpp` file contains a class representing a graph. The class includes the following methods:

- `loadGraph`: Accepts an adjacency matrix and loads it into the graph.
- `printGraph`: Prints the representation of the graph (format of your choice, see example in `Demo.cpp`).

The `Algorithms.cpp` file contains implementations for graph algorithms, including:

- `isConnected(g)`: Determines if the graph is connected (returns 1 if connected, otherwise 0).
- `shortestPath(g, start, end)`: Finds the shortest path between two vertices in the graph. If there's no such path, returns -1.
- `isContainsCycle(g)`: Detects and prints any cycle in the graph. Returns 0 if no cycle exists.
- `isBipartite(g)`: Determines if the graph can be partitioned into a bipartite graph. Returns 0 if not possible.
- `negativeCycle(g)`: Finds a negative cycle in the graph (a cycle with negative weights). Prints "No negative cycle detected" if none exists.
