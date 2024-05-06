/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/
#include "Graph.hpp"
#include <string>
namespace ariel {

    class Algorithms {
    public:
        static int isConnected(Graph graph);
        static std::string shortestPath(Graph graph, int start, int end);
        static std::string isBipartite(Graph graph);
        static std::string isContainsCycle(Graph graph);
        static std::string negativeCycle(Graph graph);
        static int numberOfEdges(Graph graph);
    };

} // namespace ariel
