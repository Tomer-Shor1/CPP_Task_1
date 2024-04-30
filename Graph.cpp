/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int numVertices) : numVertices(numVertices) {
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    // Method to load the graph from a given adjacency matrix
    void loadGraph(const vector<vector<int>>& graph) {
        // Check if the graph is square
        if (graph.size() != graph[0].size()) {
            throw invalid_argument("The graph must be square.");
        }
        // Check if the graph is empty
        if (graph.empty()) {
            throw invalid_argument("The graph cannot be empty.");
        }
        // Assuming all test passed, assign graph to adjMatrix.
        adjMatrix = graph;
    }


    // Method to print the adjacency matrix.
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }


    // Method to count the number of edges.
    int numberOfEdges() {
        int edgeCount = 0;
        for (int i = 0; i < numVertices; i++) {
            for (int j = i + 1; j < numVertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    edgeCount++;
                }
            }
        }
        return edgeCount;
    }

    int getNumOfVertices(){
        return numVertices;
    }
};




// For testing purpose.
int main() {
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    Graph g(3); // Create a graph with 3 vertice
    g.loadGraph(graph); // Load the graph to the object
    g.printGraph(); // Print the adjacency matrix
    cout << g.numberOfEdges() << "";

    return 0;
}
