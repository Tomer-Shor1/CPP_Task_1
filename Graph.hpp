/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;
        int numVertices;

    public:
        Graph();
        void loadGraph(std::vector<std::vector<int>>& graph);
        void printGraph();
        int numberOfEdges();
        int getNumOfVertices();
        std::vector<std::vector<int>> getAdjMatrix();
    };
}

#endif // GRAPH_HPP
