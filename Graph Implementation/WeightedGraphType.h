#ifndef WeightedGraph_H_INCLUDED
#define WeightedGraph_H_INCLUDED
#include "Graph.h"

class WeightedGraph : public Graph{
public:
    WeightedGraph(int size);
    void createWeightedGraph(int **graph, int n, int m);
    void shortestPath(int vertex);
    void printShortestPath();
    ~WeightedGraph();
private:
    int **weightedGraph;
    int *weights;
};

#include "WeightedGraph.cpp"

#endif // GRAPH_H_INCLUDED