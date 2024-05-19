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
        int isDirected();
        Graph& operator+(const Graph &other);
        Graph &operator+=(const Graph &other);
        Graph operator+() const;
        Graph &operator-(const Graph &other);
        Graph &operator-=(const Graph &other);
        Graph operator-() const;
        bool operator==(const Graph &other);
        bool operator!=(const Graph &other);
        bool operator>( Graph &other);
        bool operator>=( Graph &other);
        bool operator<( Graph &other);
        bool operator<=( Graph &other);
        Graph &operator++();
        Graph &operator--();
        Graph &operator*(int scalar);
        Graph operator*(const Graph &other);
    };
}

#endif // GRAPH_HPP
