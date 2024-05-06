#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool hasPath(int start, int end) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == end) {
                return true; // Path found
            }

            for (int v = 0; v < numVertices; ++v) {
                if (adjMatrix[u][v] && !visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        return false; // Path not found
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.printGraph();

    std::cout << "Path between 0 and 4: " << (g.hasPath(0, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Path between 2 and 4: " << (g.hasPath(2, 4) ? "Yes" : "No") << std::endl;

    return 0;
}
