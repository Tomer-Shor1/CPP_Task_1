#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "Algorithms.hpp"

int main() {
    std::ofstream readmeFile("README.md");

    if (readmeFile.is_open()) {
        readmeFile << "# Graph Class\n\n";
        readmeFile << "The `Graph` class represents a graph data structure and provides various operations for working with graphs.\n\n";
        readmeFile << "## Class Members\n\n";
        readmeFile << "- `isValidGraph`: Checks if a given adjacency matrix represents a valid graph.\n";
        readmeFile << "- `loadGraph`: Loads a graph from a given adjacency matrix.\n";
        readmeFile << "- `printGraph`: Prints the adjacency matrix of the graph.\n";
        readmeFile << "- `numberOfEdges`: Calculates the number of edges in the graph.\n";
        readmeFile << "- `getNumOfVertices`: Returns the number of vertices in the graph.\n";
        readmeFile << "- `getAdjMatrix`: Returns the adjacency matrix of the graph.\n";
        readmeFile << "- `isDirected`: Checks if the graph is directed or undirected.\n\n";

        readmeFile << "## Algorithms\n\n";
        readmeFile << "The `Algorithms.hpp` file contains implementations of various graph algorithms. Here is a brief overview of the algorithms implemented:\n\n";
        readmeFile << "- `isDirected`: Checks whether a graph is directed or undirected.\n";
        readmeFile << "- `isConnected`: Checks whether a graph is connected.\n";
        readmeFile << "- `shortestPath`: Finds the shortest path between two vertices in a graph.\n";
        readmeFile << "- `isBipartite`: Checks whether a graph is bipartite.\n";
        readmeFile << "- `isContainsCycle`: Checks whether a graph contains a cycle.\n";
        readmeFile << "- `negativeCycle`: Checks whether a graph contains a negative cycle.\n";
        readmeFile << "- `numberOfEdges`: Calculates the number of edges in a graph.\n\n";

        readmeFile.close();
        std::cout << "README.md file created successfully." << std::endl;
    } else {
        std::cerr << "Unable to open README.md file." << std::endl;
        return 1;
    }

    return 0;
}
