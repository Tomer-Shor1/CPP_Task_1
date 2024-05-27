/*
    ID: 325511541
    MAIL: tomer5469@gmail.com
*/

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "The cycle is: 0->2->1->0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={2, 0}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test isDirected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isDirected(g) == 1);

    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isDirected(g) == 0);
}

TEST_CASE("Test isValidGraph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Graph::isValidGraph(graph) == 1);

    std::vector<std::vector<int>> invalidGraph = {
        {0, 1},
        {0, 2},
        {2, 4}};
    CHECK_THROWS(g.loadGraph(invalidGraph));
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, -2, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "Graph contains negative cycles: 1->0->1->1");

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "The graph has no negative cycles");
}

TEST_CASE("Test numberOfEdges")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::numberOfEdges(g) == 2);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::numberOfEdges(g) == 4);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {// Undirected graph with a path
                                  {0, 1, 0},
                                  {1, 0, 1},
                                  {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 3)); // Invalid end index

    vector<vector<int>> graph2 = {// Undirected graph without a path
                                  {0, 1, 1, 0, 0},
                                  {1, 0, 1, 0, 0},
                                  {1, 1, 0, 1, 0},
                                  {0, 0, 1, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {// Directed graph with a path (working with negative and non-negative weights)
                                  {0, 1, 0, 2},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, -1},
                                  {0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");

    vector<vector<int>> graph4 = {// Directed graph with a path (Negative cycle)
                                  {0, 0, -2, 0, 0},
                                  {0, 0, 0, 5, 2},
                                  {1, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0},
                                  {0, 0, 0, -1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 3) == "1->4->3");

    vector<vector<int>> graph5 = {// Directed graph without a path (Negative cycle)
                                  {0, 1, 0},
                                  {1, 0, 1},
                                  {-3, 0, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

    vector<vector<int>> graph6 = {// Undirected graph with a path (Negative cycle)
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, -3},
                                  {1, 0, -3, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");

    vector<vector<int>> graph7 = {// Undirected graph without a path (Negative cycle)
                                  {0, -2, 1, 0},
                                  {-2, 0, -1, 0},
                                  {1, -1, 0, 0},
                                  {0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

    vector<vector<int>> graph8 = {// Shortest path = 0
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, -2},
                                  {1, 0, -2, 0}};
    g.loadGraph(graph8);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {// Undirected bipartite graph
                                  {0, 1, 0},
                                  {1, 0, 1},
                                  {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={2, 0}, B={1}");

    vector<vector<int>> graph2 = {// Undirected non-bipartite graph
                                  {0, 1, 1, 0, 0},
                                  {3, 0, 2, 0, 0},
                                  {2, 1, 0, 1, 0},
                                  {0, 0, 8, 0, 0},
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {// Directed bipatite graph
                                  {0, 2, 0, 0, 0},
                                  {0, 0, 7, 0, 0},
                                  {0, 0, 0, 2, 0},
                                  {0, 0, 0, 0, 1},
                                  {0, 2, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={4, 2, 0}, B={3, 1}");

    vector<vector<int>> graph4 = {// Directed non-bipatite graph
                                  {0, 1, 0, 0, 0},
                                  {0, 0, 6, 0, 0},
                                  {0, 0, 0, 6, 0},
                                  {0, 0, 0, 0, 7},
                                  {6, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("+ operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3.getAdjMatrix() == vector<vector<int>>{{0, 2, 1}, {2, 0, 2}, {1, 2, 0}});
}

TEST_CASE("+= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    g1 += g2;
    CHECK(g1.getAdjMatrix() == vector<vector<int>>{{0, 2, 1}, {2, 0, 2}, {1, 2, 0}});
}

TEST_CASE("Unary + operator")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = +g;
    CHECK(g2.getAdjMatrix() == graph);
}

TEST_CASE("- operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    CHECK(g3.getAdjMatrix() == std::vector<std::vector<int>>{
                                   {0, 0, -1},
                                   {0, 0, 0},
                                   {-1, 0, 0}});
}

TEST_CASE("-= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    g1 -= g2;
    CHECK(g1.getAdjMatrix() == std::vector<std::vector<int>>{
                                   {0, 0, -1},
                                   {0, 0, 0},
                                   {-1, 0, 0}});
}

TEST_CASE("Unary - operator")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = -g;
    CHECK(g2.getAdjMatrix() == vector<vector<int>>{{0, -1, -1}, {-1, 0, -1}, {-1, -1, 0}});
}

TEST_CASE("== operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 == g2);
}

TEST_CASE("!= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 != g2);
}

TEST_CASE("> operator")
{
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    // g2 has more edges (5) than g1 (4)
    CHECK(g2 > g1);
}

TEST_CASE(">= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g2 >= g1);
}

TEST_CASE("< operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
}

TEST_CASE("<= operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 <= g2);
}

TEST_CASE("++ operator") {
    ariel::Graph g;
    std::vector<std::vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g.loadGraph(graph);

    ++g;
    CHECK(g.getAdjMatrix() == std::vector<std::vector<int>>{{0, 2, 2}, {2, 0, 2}, {2, 2, 0}});
}

TEST_CASE("-- operator")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 2, 2},
        {2, 0, 2},
        {2, 2, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = --g;
    CHECK(g2.getAdjMatrix() == vector<vector<int>>{{0, 1, 1}, {1, 0, 1}, {1, 1, 0}});
}

TEST_CASE("* operator")
{
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 * g2;
    CHECK(g3.getAdjMatrix() == vector<vector<int>>{{1, 0, 1}, {1, 2, 1}, {1, 0, 1}});
}

TEST_CASE("* operator (scalar)")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph);

    ariel::Graph g2 = g * 2;
    CHECK(g2.getAdjMatrix() == vector<vector<int>>{{0, 2, 2}, {2, 0, 2}, {2, 2, 0}});
}


