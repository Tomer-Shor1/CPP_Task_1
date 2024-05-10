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
        unsigned long numVertices;

    public:
        Graph();
        static int isValidGraph(std::vector<std::vector<int>> &graph);
        void loadGraph(std::vector<std::vector<int>> &graph);
        void printGraph();
        unsigned long numberOfEdges();
        unsigned long getNumOfVertices();
        std::vector<std::vector<int>> getAdjMatrix();
    };
}

#endif // GRAPH_HPP
