#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "UnorderedLinkedList.h"

class Graph{
public:
    Graph(int size);
    void createGraph(int **graph, int n, int m);
    void clear();
    void print();
    bool isEmpty();
    void bfs();
    void dfs(int vertex, bool visited[]);
    void depthFirstTraversal();
    ~Graph();
protected:
    int verticesCount;
    UnorderedLinkedList<int> *graph;
};

#include "Graph.cpp"

#endif // GRAPH_H_INCLUDED