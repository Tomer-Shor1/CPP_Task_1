/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#include <vector>
#include <iostream>
#include "Graph.hpp"

namespace ariel {
        Graph::Graph() : numVertices(0) {}

        int Graph::isValidGraph(std::vector<std::vector<int>>& graph) {
            if (graph.size() != 0 && graph.size() == graph[0].size()) {
                return 1; // Valid graph
            } else {
                return 0; // Invalid graph
            }
        }


        void Graph::loadGraph(std::vector<std::vector<int>>& graph) {
            if (isValidGraph(graph) == 0)
            {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
            
            numVertices = (unsigned long)graph.size();
            adjMatrix = graph; // Directly assign the input graph to adjMatrix
        }

        void Graph::printGraph() {
            for (const auto& row : adjMatrix) {
                for (int val : row) {
                    std::cout << val << ' ';
                }
                std::cout << '\n';
            }
        }

        unsigned long Graph::numberOfEdges() {
            unsigned long count = 0;
            for (const auto& row : adjMatrix) {
                for (int val : row) {
                    if (val == 1) {
                        count++;
                    }
                }
            }
            // Since the graph is undirected, we divide the count by 2
            return count / 2;
        }

        unsigned long Graph::getNumOfVertices() {
            return numVertices;
        }

        std::vector<std::vector<int>> Graph::getAdjMatrix() {
            return adjMatrix;
        }
    };






// // // For testing purpose.
// int main() {
//     std::vector<std::vector<int>> graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}
//     };

//     ariel::Graph g; // Create a graph with 3 vertice
//     g.loadGraph(graph); // Load the graph to the object
//     g.printGraph(); // Print the adjacency matrix
//     std::cout << g.numberOfEdges() << "";

//     return 0;
// }
