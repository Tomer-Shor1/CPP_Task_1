/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#include <vector>
#include <iostream>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        int numVertices;

    public:
        Graph() : numVertices(0) {}

        void loadGraph(std::vector<std::vector<int>>& graph) {
            numVertices = graph.size();
            adjMatrix = graph; // Directly assign the input graph to adjMatrix
        }

        void printGraph() {
            for (const auto& row : adjMatrix) {
                for (int val : row) {
                    std::cout << val << ' ';
                }
                std::cout << '\n';
            }
        }

        int numberOfEdges() {
            int count = 0;
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

        int getNumOfVertices() {
            return numVertices;
        }

        std::vector<std::vector<int>> getAdjMatrix() {
            return adjMatrix;
        }
    };
}





// // For testing purpose.
int main() {
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    ariel::Graph g; // Create a graph with 3 vertice
    g.loadGraph(graph); // Load the graph to the object
    g.printGraph(); // Print the adjacency matrix
    std::cout << g.numberOfEdges() << "";

    return 0;
}
