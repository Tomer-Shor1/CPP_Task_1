/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> adjMatrix;
    int numVertices;

public:
    Graph(int numVertices);
    /*
        Loads a givin graph into the graph object.
        Note: The graph is unchangeable.
    */
    void loadGraph(const std::vector<std::vector<int>>& graph);

    /*
        This function prints the graph.
    */
    void printGraph();

    /*
        This function returns the number of edges in the graph.
    */
    int numberOfEdges();

    /*
        Return the number of vertices.
    */
    int getNumOfVertices();
};

#endif // GRAPH_HPP
