/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#include "Graph.hpp"

/*
    *The function checks if the graph is connected.
    *Returns 1 if true, else 0.
    @Param graph - the graph to check.
*/
int isConnected(Graph graph);

/*
    
*/
int shortestPath(Graph graph,int start,int end);

/*
    This fucntion check whether the graph is bipartite.
    If it is, then the fucntion will return the two groups, else return 0.
    @param graph - the graph to check.
*/
int isBipartite(Graph graph);

/*
    This function checks whether a negative cycle exists in the graph.
    If true, the fucntion will return the negative cycle, else prints "No negative cycle."
    @param graph - the graph to check.
*/
int negativeCycle(Graph graph);


int numberOfEdges(Graph graph);
    
