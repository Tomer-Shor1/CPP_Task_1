# **CPP FIRST TASK**
Written by Tomer Shor.
12/05/2024.



# **Graph Class Documentation**

This document provides an overview of the **Graph** class, including its methods and usage. The **Graph** class is designed to represent and manipulate graphs, supporting operations such as loading a graph from an adjacency matrix, printing the graph, counting the number of edges, and determining the graph's directionality.

## **Constructor**

Initializes a new instance of the **Graph** class with no vertices.

## **Methods**

### `isValidGraph(std::vector<std::vector<int>>& graph)`

Checks if the provided adjacency matrix represents a valid graph. Returns `1` if the graph is valid (square matrix) and `0` otherwise.

### `loadGraph(std::vector<std::vector<int>>& graph)`

Loads a graph from an adjacency matrix. Throws an exception if the graph is invalid. Assigns the number of vertices (`numVertices`) and sets the adjacency matrix (`adjMatrix`) to the input graph.

### `printGraph()`

Prints the adjacency matrix of the graph to the console.

### `numberOfEdges()`

Returns the number of edges in the graph. Divides the count by 2 for undirected graphs since each edge is counted twice.

### `getNumOfVertices()`

Returns the number of vertices in the graph.

### `getAdjMatrix()`

Returns the adjacency matrix of the graph.

### `isDirected()`

Determines if the graph is directed or undirected. Returns `1` for directed graphs and `0` for undirected graphs. 



# Graph Algorithms Library

This library provides a set of algorithms for graph processing, including depth-first search (DFS), connectivity check, shortest path finding using Bellman-Ford, bipartiteness check, cycle detection, and negative cycle detection. These algorithms are implemented within the `Algorithms` namespace and utilize a `Graph` object for graph representation.

## Table of Contents

- [Algorithms](#algorithms)
  - [Depth-First Search (DFS)](#depth-first-search-dfs)
  - [Connectivity Check](#connectivity-check)
  - [Shortest Path (Bellman-Ford)](#shortest-path-bellman-ford)
  - [Bipartiteness Check](#bipartiteness-check)
  - [Cycle Detection](#cycle-detection)
  - [Negative Cycle Detection](#negative-cycle-detection)
  - [Number of Edges](#number-of-edges)

## Depth-First Search (DFS)

- **Function:** `void DFS(unsigned long v, Graph& graph, std::vector<bool>& visited)`
- **Description:** Implements the Depth-First Search (DFS) algorithm to traverse or search through the graph. Starting from a given vertex `v`, it explores as far as possible along each branch before backtracking. The `visited` vector keeps track of which vertices have been visited to avoid revisiting them.
- **Parameters:**
  - `v`: The starting vertex for the DFS traversal.
  - `graph`: The Graph object representing the graph to be traversed.
  - `visited`: A vector indicating which vertices have been visited during the traversal.

## Connectivity Check

- **Function:** `int isConnected(Graph graph)`
- **Description:** Checks if the graph is connected, meaning there is a path between every pair of vertices. It performs a DFS from each vertex and returns 1 (success) if all vertices are reachable from each other, indicating the graph is connected. Otherwise, it returns 0 (failure).
- **Parameter:** `graph`: The Graph object representing the graph to be checked.

## Shortest Path (Bellman-Ford)

- **Function:** `std::string shortestPath(Graph g, size_t start, size_t end)`
- **Description:** Finds the shortest path from the start vertex to the end vertex using the Bellman-Ford algorithm. It handles graphs with negative weights but cannot detect negative cycles. If no path exists, or there exist negative cycle in the path, it returns -1. 
- **Parameters:**
  - `g`: The Graph object representing the graph.
  - `start`: The starting vertex for the path search.
  - `end`: The ending vertex for the path search.

## Bipartiteness Check

- **Function:** `std::string isBipartite(Graph graph)`
- **Description:** Determines if the graph is bipartite, meaning its vertices can be divided into two disjoint sets such that every edge connects a vertex in one set to a vertex in the other set. It uses a modified version of BFS to color the vertices and checks for conflicts.
- **Parameter:** `graph`: The Graph object representing the graph to be checked.

## Cycle Detection

- **Function:** `std::string isContainsCycle(Graph graph)`
- **Description:** Detects if the graph contains a cycle. It uses a modified DFS to keep track of the parent of each vertex and checks for back edges, which indicate a cycle.
- **Parameter:** `graph`: The Graph object representing the graph to be checked.

## Negative Cycle Detection

- **Function:** `std::string negativeCycle(Graph graph)`
- **Description:** Identifies if the graph contains a negative cycle, which is a cycle whose total weight is negative. It uses the Bellman-Ford algorithm to detect such cycles. If negative cycle been found, the function prints it.
- **Parameter:** `graph`: The Graph object representing the graph to be checked.

## Number of Edges

- **Function:** `int numberOfEdges(Graph graph)`
- **Description:** Counts the number of edges in the graph. 
- **Parameter:** `graph`: The Graph object representing the graph to be analyzed.





