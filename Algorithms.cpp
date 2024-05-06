/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/

#include <queue>
#include <limits>
#include <string>
#include "Algorithms.hpp"
#include <unordered_set>
#include <stack>

namespace ariel {

        void DFS(int v, Graph& graph, std::vector<bool>& visited) {
            visited[v] = true;

            // Visit all adjacent vertices of v
            for (int i = 0; i < graph.getNumOfVertices(); ++i) {
                if (graph.getAdjMatrix()[v][i] && !visited[i]) {
                    DFS(i, graph, visited);
                }
            }
        }

        int Algorithms::isConnected(Graph graph) {
            int numVertices = graph.getNumOfVertices();

            // Perform a depth-first search (DFS) from each vertex
            for (int i = 0; i < numVertices; ++i) {
                std::vector<bool> visited(numVertices, false);
                DFS(i, graph, visited);

                // Check if all vertices were visited
                for (bool v : visited) {
                    if (!v) {
                        return 0; // Not all vertices were visited, graph is not connected
                    }
                }
            }

            return 1; // All vertices were visited from each vertex, graph is connected
        }

        std::string Algorithms::shortestPath(Graph graph, int start, int end) {
            int numVertices = graph.getNumOfVertices();

            // Initialize distances from start to all other vertices as INFINITE
            std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
            dist[start] = 0;

            // Priority queue to store vertices and their distances
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
            pq.push(std::make_pair(0, start));

            // Array to store the shortest path tree
            std::vector<int> parent(numVertices, -1);

            // Find shortest path using Dijkstra's algorithm
            while (!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                // Update distance value of adjacent vertices of u
                for (int v = 0; v < numVertices; ++v) {
                    if (graph.getAdjMatrix()[u][v] && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph.getAdjMatrix()[u][v];
                        parent[v] = u;
                        pq.push(std::make_pair(dist[v], v));
                    }
                }
            }

            // Construct the path from start to end
            std::string path;
            for (int v = end; v != -1; v = parent[v]) {
                path = std::to_string(v) + "->" + path;
            }

            if (path.empty()) {
                return "No path found";
            } else {
                path.pop_back(); // Remove the extra "->" at the end
                return "The path is: "+ path;
            }
        }
        std::string Algorithms::isBipartite(Graph graph) {
            return 0; // Placeholder
        }

        std::string Algorithms::isContainsCycle(Graph graph) {
            int numVertices = graph.getNumOfVertices();
            std::vector<bool> visited(numVertices, false);
            std::vector<int> parent(numVertices, -1);
            std::unordered_set<int> cycleVertices;
            std::stack<int> stack;

            for (int i = 0; i < numVertices; ++i) {
                if (!visited[i]) {
                    stack.push(i);
                    while (!stack.empty()) {
                        int u = stack.top();
                        stack.pop();
                        visited[u] = true;
                        for (int v = 0; v < numVertices; ++v) {
                            if (graph.getAdjMatrix()[u][v]) {
                                if (!visited[v]) {
                                    stack.push(v);
                                    parent[v] = u;
                                } else if (parent[u] != v && cycleVertices.find(v) == cycleVertices.end()) {
                                    // Found a cycle
                                    int curr = u;
                                    std::string cycle;
                                    while (curr != v) {
                                        cycle = std::to_string(curr) + "->" + cycle;
                                        cycleVertices.insert(curr);
                                        curr = parent[curr];
                                    }
                                    cycle = std::to_string(v) + "->" + cycle + std::to_string(v);
                                    return "The cycle is: " + cycle;
                                }
                            }
                        }
                    }
                }
            }

            return ""; // No cycle found
        }

        std::string Algorithms::negativeCycle(Graph graph) {
            int numVertices = graph.getNumOfVertices();
            std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
            std::vector<int> parent(numVertices, -1);
            int lastUpdatedVertex = -1;

            // Relax all edges |V| - 1 times
            for (int i = 1; i < numVertices; ++i) {
                for (int u = 0; u < numVertices; ++u) {
                    for (int v = 0; v < numVertices; ++v) {
                        if (graph.getAdjMatrix()[u][v] != 0 && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                            dist[v] = dist[u] + graph.getAdjMatrix()[u][v];
                            parent[v] = u;
                            lastUpdatedVertex = v;
                        }
                    }
                }
            }

            // Check for negative cycle
            for (int u = 0; u < numVertices; ++u) {
                for (int v = 0; v < numVertices; ++v) {
                    if (graph.getAdjMatrix()[u][v] != 0 && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                        // Negative cycle found, construct and return the cycle
                        std::string cycle = std::to_string(v);
                        int curr = parent[v];
                        while (curr != v) {
                            cycle = std::to_string(curr) + "->" + cycle;
                            curr = parent[curr];
                        }
                        cycle = std::to_string(v) + "->" + cycle + std::to_string(v);
                        return cycle;
                    }
                }
            }

            if (lastUpdatedVertex != -1) {
                // Construct and return the path to the last updated vertex
                std::string path = std::to_string(lastUpdatedVertex);
                int curr = parent[lastUpdatedVertex];
                while (curr != -1 && curr != lastUpdatedVertex) {
                    path = std::to_string(curr) + "->" + path;
                    curr = parent[curr];
                }
                path = std::to_string(lastUpdatedVertex) + "->" + path + std::to_string(lastUpdatedVertex);
                return path;
            }

            return "The graph has no negative cycles";
        }

        int Algorithms::numberOfEdges(Graph graph) {
            return 0; // Placeholder
        }
} 







