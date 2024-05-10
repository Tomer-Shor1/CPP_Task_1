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
#include <unordered_set>
#include <sstream>
#define SUCCESS 1
#define FAILURE 0
namespace ariel {


        /* 
            Function to check wheter a graph is directed.
            @param - The graph to check.
            Returns 1 if the graph is directed, 0 else.
        */
        int Algorithms::isDirected(Graph graph){
            for (size_t i = 0; i < graph.getNumOfVertices(); i++)
            {
                for (size_t j = 0; j < graph.getNumOfVertices(); j++)
                {
                    if (graph.getAdjMatrix()[i][j] != graph.getAdjMatrix()[j][i])
                    {
                        return 1;
                    }
                    
                }
            }
            return 0;
        }
        /*
            Depth-first search (DFS) algorithm.
            @param v - The start vertex.
            @param graph - the graph to perfoem DFS on.
            @param visited - A verctor contains visited vertics.
        */
        void DFS(unsigned long v, Graph& graph, std::vector<bool>& visited) {
            visited[v] = true;

            // Visit all adjacent vertices of v
            for (unsigned long i = 0; i < graph.getNumOfVertices(); ++i) {
                if (graph.getAdjMatrix()[v][i] && !visited[i]) {
                    DFS(i, graph, visited);
                }
            }
        }

        /*
            This algoritms checks wheter a given graph is connected.
            @param graph - The graph the check is being made on.
            Returns 1 if connected, else - 0.
        */
        int Algorithms::isConnected(Graph graph) {
            unsigned long numVertices = graph.getNumOfVertices();

            // Perform a DFS from each vertex
            for (unsigned long i = 0; i < numVertices; ++i) {
                std::vector<bool> visited(numVertices, false);
                DFS(i, graph, visited);

                // Check if all vertices were visited
                for (bool v : visited) {
                    if (!v) {
                        return FAILURE; // Not all vertices were visited, graph is not connected
                    }
                }
            }

            return SUCCESS; // All vertices were visited from each vertex, graph is connected
        }


        /*
            Bellman Ford method to find the shortest path start ~~~> end (from start to end).
            @param graph - the graph the vertices are in.
            @param start - start vertex.
            @param end - end vertex 
            Returns the shortest path. If no path has been found, the function will print "-1". If the graph contains a negative cycle, the function will return failure.
        */
        std::string Algorithms::shortestPath(Graph graph, unsigned long start, unsigned long end) {
            unsigned long numVertices = graph.getNumOfVertices();

            // Initialize distances from start to all other vertices as INFINITE, Set start vertex distance to 0.
            std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
            dist[start] = 0;

            std::vector<int> parent(numVertices, -1);

            // Relax all edges |V| - 1 times. A simple shortest 
            // path from start to any other vertex can have at-most |V| - 1 edges
            for (unsigned long i = 1; i <= numVertices - 1; i++) {
                for (unsigned long u = 0; u < numVertices; u++) {
                    for (unsigned long v = 0; v < numVertices; v++) {
                        if (graph.getAdjMatrix()[u][v] && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                            dist[v] = dist[u] + graph.getAdjMatrix()[u][v];
                            parent[v] = u; // Update the parent of vertex v
                        }
                    }
                }
            }

            // Check for negative-weight cycles. The above step 
            // guarantees shortest distances if graph doesn't contain negative weight cycle. If we get a shorter path, then there is a cycle.
            for (unsigned long u = 0; u < numVertices; u++) {
                for (unsigned long v = 0; v < numVertices; v++) {
                    if (graph.getAdjMatrix()[u][v] && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                        return "Graph contains negative weight cycle";
                    }
                }
            }

            // Construct the path from start to end
            std::string path;
            for (unsigned long v = end; v != start; v = (unsigned long)parent[v]) {
                path = std::to_string(v) + "->" + path;
            }
            path = std::to_string(start) + "->" + path;

            if (dist[end] == std::numeric_limits<int>::max()) {
                return "-1";
            } else {
                path.pop_back(); // Remove the extra ">" at the end.
                path.pop_back(); // Remove the extra "-" at the end.
                return path;
            }
        }


        /*
            This fucntion chekcs whether a graph is bipartite.
            @param graph - the graph to make the check on.
            returns "Bipartite or Not Bipartite."
        */
        std::string Algorithms::isBipartite(Graph graph) {
            unsigned long numVertices = graph.getNumOfVertices();
            std::vector<int> color(numVertices, -1); // Initialize all vertices as uncolored (-1)

            // Queue for BFS traversal
            std::queue<unsigned long> q;

            // Start BFS from vertex 0
            q.push(0);
            color[0] = 1; // Color vertex 0 as 1 (first color)

            // Separate groups for A and B
            std::unordered_set<unsigned long> groupA, groupB;

            groupA.insert(0); // Add vertex 0 to group A

            while (!q.empty()) {
                unsigned long u = q.front();
                q.pop();

                // Add u to the appropriate group
                if (color[u] == 1) {
                    groupA.insert(u);
                } else {
                    groupB.insert(u);
                }

                // Visit all adjacent vertices of u
                for (unsigned long v = 0; v < numVertices; ++v) {
                    // If there is an edge from u to v and v is not colored
                    if (graph.getAdjMatrix()[u][v] && color[v] == -1) {
                        // Color v with a different color than u
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    // If there is an edge from u to v and both u and v have the same color, the graph is not bipartite
                    else if (graph.getAdjMatrix()[u][v] && color[v] == color[u]) {
                        return "0";
                    }
                }
            }

            // Construct the output string
            std::stringstream ss;
            ss << "The graph is bipartite: A={";
            for (auto it = groupA.begin(); it != groupA.end(); ++it) {
                ss << *it;
                if (std::next(it) != groupA.end()) {
                    ss << ", ";
                }
            }
            ss << "}, B={";
            for (auto it = groupB.begin(); it != groupB.end(); ++it) {
                ss << *it;
                if (std::next(it) != groupB.end()) {
                    ss << ", ";
                }
            }
            ss << "}";
            
            return ss.str();
        }

        /*
            1
        */
        std::string Algorithms::isContainsCycle(Graph graph) {
            unsigned long numVertices = graph.getNumOfVertices();
            std::vector<bool> visited(numVertices, false);
            std::vector<int> parent(numVertices, -1);
            std::unordered_set<int> cycleVertices;
            std::stack<int> stack;

            for (unsigned long i = 0; i < numVertices; ++i) {
                if (!visited[i]) {
                    stack.push(i);
                    while (!stack.empty()) {
                        unsigned long u = (unsigned long)stack.top();
                        stack.pop();
                        visited[u] = true;
                        for (unsigned long v = 0; v < numVertices; ++v) {
                            if (graph.getAdjMatrix()[u][v]) {
                                if (!visited[v]) {
                                    stack.push(v);
                                    parent[v] = u;
                                } else if (parent[u] != v && cycleVertices.find(v) == cycleVertices.end()) {
                                    // Found a cycle
                                    unsigned long curr = u;
                                    std::string cycle;
                                    while (curr != v) {
                                        cycle = std::to_string(curr) + "->" + cycle;
                                        cycleVertices.insert(curr);
                                        curr = (unsigned long)parent[curr];
                                    }
                                    cycle = std::to_string(v) + "->" + cycle + std::to_string(v);
                                    return "The cycle is: "+ cycle;
                                }
                            }
                        }
                    }
                }
            }

            return "0";    // no cycle found
        }

        std::string Algorithms::negativeCycle(Graph graph) {
            unsigned long numVertices = graph.getNumOfVertices();
            std::vector<int> dist(numVertices, std::numeric_limits<int>::max());
            std::vector<int> parent(numVertices, -1);
            int lastUpdatedVertex = -1;

            // Relax all edges |V| - 1 times
            for (unsigned long i = 0; i < numVertices - 1; ++i) {
                for (unsigned long u = 0; u < numVertices; ++u) {
                    for (unsigned long v = 0; v < numVertices; ++v) {
                        if (graph.getAdjMatrix()[u][v] != 0 && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                            dist[v] = dist[u] + graph.getAdjMatrix()[u][v];
                            parent[v] = u;
                            lastUpdatedVertex = v;
                        }
                    }
                }
            }

            // Check for negative cycle
            for (unsigned long u = 0; u < numVertices; ++u) {
                for (unsigned long v = 0; v < numVertices; ++v) {
                    if (graph.getAdjMatrix()[u][v] != 0 && dist[u] + graph.getAdjMatrix()[u][v] < dist[v]) {
                        // Negative cycle found, construct and return the cycle
                        std::string cycle = std::to_string(v);
                        unsigned long curr = (unsigned long)parent[v];
                        while (curr != v) {
                            cycle = std::to_string(curr) + "->" + cycle;
                            curr = (unsigned long)parent[curr];
                        }
                        cycle = std::to_string(v) + "->" + cycle + std::to_string(v);
                        return cycle;
                    }
                }
            }

            if (lastUpdatedVertex != -1) {
                // Construct and return the path to the last updated vertex
                std::string path = std::to_string(lastUpdatedVertex);
                unsigned long curr = (unsigned long)parent[(unsigned long)lastUpdatedVertex];
                while (curr != -1 && curr != lastUpdatedVertex) {
                    path = std::to_string(curr) + "->" + path;
                    curr = (unsigned long)parent[curr];
                }
                path = std::to_string(lastUpdatedVertex) + "->" + path;
                return path;
            }

            return "The graph has no negative cycles";
        }


        int Algorithms::numberOfEdges(Graph graph) {
            unsigned long numVertices = graph.getNumOfVertices();
            unsigned long numEdges = 0;

            for (unsigned long i = 0; i < numVertices; ++i) {
                for (unsigned long j = 0; j < numVertices; ++j) {
                    if (graph.getAdjMatrix()[i][j] != 0) {
                        ++numEdges;
                    }
                }
            }

            // Each edge is counted twice (once for each vertex it connects), so divide by 2
            return numEdges / 2;
        }
}







