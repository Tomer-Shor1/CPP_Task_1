/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#include <vector>
#include <iostream>
#include "Graph.hpp"

namespace ariel {
        Graph::Graph() : numVertices(0) {}



        // check whether the graph is valid
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
            if (isDirected())
            {
                return count;
            }
            else{
            // Since the graph is undirected, we divide the count by 2
            return count / 2;
            }
        }

        unsigned long Graph::getNumOfVertices() {
            return numVertices;
        }

        std::vector<std::vector<int>> Graph::getAdjMatrix() {
            return adjMatrix;
        }


        // check whther a graph is directed
        int Graph::isDirected() {
            // Check if the graph is square
            if (adjMatrix.size() != adjMatrix[0].size()) {
                return -1; // Not a valid graph representation
            }

            // Check if the graph is directed or undirected
            for (size_t i = 0; i < adjMatrix.size(); i++) {
                for (size_t j = 0; j < adjMatrix[i].size(); j++) {
                    if (adjMatrix[i][j] != adjMatrix[j][i]) {
                        return 1; // Directed graph
                    }
                }
            }

            return 0; // Undirected graph
        }

    };

