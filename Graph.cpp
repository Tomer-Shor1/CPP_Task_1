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

        // operators overloading
        Graph& Graph::operator=(const Graph& other) {
            if (this == &other) {
                return *this;
            }

            numVertices = other.numVertices;
            adjMatrix = other.adjMatrix;

            return *this;
        }


        // addition operator
        Graph& Graph::operator+(const Graph& other) {
            if (numVertices != other.numVertices) {
                throw std::invalid_argument("Invalid operation: The two graphs have different number of vertices.");
            }

            Graph newGraph;
            newGraph.numVertices = numVertices;
            newGraph.adjMatrix = adjMatrix;
            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    newGraph.adjMatrix[i][j] = adjMatrix[i][j] + other.adjMatrix[i][j];
                }
            }
            return newGraph;
        }

        // addition assignment operator
        Graph& Graph::operator+=(const Graph& other) {
            if (numVertices != other.numVertices) {
                throw std::invalid_argument("Invalid operation: The two graphs have different number of vertices.");
            }

            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    adjMatrix[i][j] += other.adjMatrix[i][j];
                }
            }
            return *this;
        }

        // unary plus operator
        Graph Graph::operator+() const {
            Graph newGraph;
            newGraph.numVertices = numVertices;
            newGraph.adjMatrix = adjMatrix;
            return newGraph;
        }

        // subtraction operator
        Graph& Graph::operator-(const Graph& other) {
            if (numVertices != other.numVertices) {
                throw std::invalid_argument("Invalid operation: The two graphs have different number of vertices.");
            }

            Graph newGraph;
            newGraph.numVertices = numVertices;
            newGraph.adjMatrix = adjMatrix;
            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    newGraph.adjMatrix[i][j] = adjMatrix[i][j] - other.adjMatrix[i][j];
                }
            }
            return newGraph;
        }

        // subtraction assignment operator
        Graph& Graph::operator-=(const Graph& other) {
            if (numVertices != other.numVertices) {
                throw std::invalid_argument("Invalid operation: The two graphs have different number of vertices.");
            }

            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    adjMatrix[i][j] -= other.adjMatrix[i][j];
                }
            }
            return *this;
        }

        // unary minus operator
        Graph Graph::operator-() const {
            Graph newGraph;
            newGraph.numVertices = numVertices;
            newGraph.adjMatrix = adjMatrix;
            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    newGraph.adjMatrix[i][j] = -adjMatrix[i][j];
                }
            }
            return newGraph;
        }

        // equality operator
        bool Graph::operator==(const Graph& other) {
            if (numVertices != other.numVertices) {
                return false;
            }

            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    if (adjMatrix[i][j] != other.adjMatrix[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }

        bool Graph::operator!=(const Graph& other) {
            return !(*this == other);
        }   

        // Helper function to check if this graph is properly contained in another graph
        bool isProperSubset(Graph& g1, Graph& g2) {
            bool hasAdditionalEdge = false;

            for (size_t i = 0; i < g1.getNumOfVertices(); ++i) {
                for (size_t j = 0; j < g1.getNumOfVertices(); ++j) {
                    if (g1.getAdjMatrix()[i][j] != 0 && g2.getAdjMatrix()[i][j] == 0) {
                        return false;
                    }
                    if (g1.getAdjMatrix()[i][j] == 0 && g2.getAdjMatrix()[i][j] != 0) {
                        hasAdditionalEdge = true;
                    }
                }
            }
            return hasAdditionalEdge;
        }

        // greater than operator
        bool Graph::operator>(Graph& other) {
            if (isProperSubset(*this, other)) {
                return true;
            } 
            else if (isProperSubset(other, *this)) {
                return false;
            }
            // compare the number of edges
            if (numberOfEdges() > other.numberOfEdges()) {
                return true;
            }
            else if (numberOfEdges() == other.numberOfEdges()) {
                return adjMatrix.size() > other.adjMatrix.size();
            }
            else {
                return false;
            }
        }

        // greater than or equal to operator
        bool Graph::operator>=(Graph& other) {
            // compare the number of edges
            if (numberOfEdges() > other.numberOfEdges()) {
                return true;
            }
            else if (numberOfEdges() == other.numberOfEdges()) {
                return adjMatrix.size() >= other.adjMatrix.size();
            }
            else {
                return false;
            }
        }

        // less than operator
        bool Graph::operator<( Graph& other) {
            if (isProperSubset(other, *this)) {
                return true;
            } 
            else if (isProperSubset(*this, other)) {
                return false;
            }
            // compare the number of edges
            if (numberOfEdges() < other.numberOfEdges()) {
                return true;
            }
            else if (numberOfEdges() == other.numberOfEdges()) {
                return adjMatrix.size() < other.adjMatrix.size();
            }
            else {
                return false;
            }
        }

        // less than or equal to operator
        bool Graph::operator<=( Graph& other) {
            // compare the number of edges
            if (numberOfEdges() < other.numberOfEdges()) {
                return true;
            }
            else if (numberOfEdges() == other.numberOfEdges()) {
                return adjMatrix.size() <= other.adjMatrix.size();
            }
            else {
                return false;
            }
        }


        // ++ operator
        Graph& Graph::operator++() {
            for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                adjMatrix[i][j]++;
            }
            }
            return *this;
        }

        // -- operator
        Graph& Graph::operator--() {
            for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                adjMatrix[i][j]--;
            }
            }
            return *this;
        }

        // scalar multiplication
        Graph& Graph::operator*(int scalar) {
            for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                adjMatrix[i][j] *= scalar;
            }
            }
            return *this;
        }

        // multiplication operator
        Graph Graph::operator*(const Graph& other) {
            if (numVertices != other.numVertices) {
                throw std::invalid_argument("Invalid operation: The two graphs have different number of vertices.");
            }

            Graph newGraph;
            newGraph.numVertices = numVertices;
            newGraph.adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));

            for (size_t i = 0; i < numVertices; i++) {
                for (size_t j = 0; j < numVertices; j++) {
                    for (size_t k = 0; k < numVertices; k++) {
                        newGraph.adjMatrix[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                    }
                }
            }

            return newGraph;
        }

        // output operator
        std::ostream& operator<<(std::ostream& os,Graph& graph) {
            for ( auto& row : graph.getAdjMatrix()) {
                for (int val : row) {
                    os << val << ' ';
                }
                os << '\n';
            }
            return os;
        }
    };

