/*
  ID: 325511541
  MAIL: tomer5469@gmail.com
*/


#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
using namespace std;
#include <limits>



int isConnected(Graph graph)
{
    if (graph.numberOfEdges() < graph.getNumOfVertices() - 1) {  //if m < n-1 cant be connected
        return 0;
    }

    
}



int minDistance(vector<int>& dist, vector<bool>& sptSet, int numberOfVertices) {
    int min = numeric_limits<int>::max(), min_index;

    for (int v = 0; v < numberOfVertices; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}




