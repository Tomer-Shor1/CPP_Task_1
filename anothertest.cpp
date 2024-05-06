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

int main() {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    std::cout << "Number of vertices: " << g.getNumOfVertices() << std::endl;
    std::cout << "Number of edges: " << g.numberOfEdges() << std::endl;
    std::cout << "Adjacency Matrix:" << std::endl;
    g.printGraph();

    return 0;
}