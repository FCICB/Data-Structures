#include <iostream>
#include "Graph.h"
#include "WeightedGraphType.h"

using namespace std;

int main(){
    int size = 5;
    int i, j;

    int v1[5] = {INT16_MAX, 16, INT16_MAX, 2, 3};
    int v2[5] = {INT16_MAX, INT16_MAX, 5, INT16_MAX, INT16_MAX};
    int v3[5] = {INT16_MAX, 3, INT16_MAX, INT16_MAX, INT16_MAX};
    int v4[5] = {INT16_MAX, 12, INT16_MAX, INT16_MAX, 7};
    int v5[5] = {INT16_MAX, 10, 4, 5, INT16_MAX};

    Graph graph(size);
    int **matrix;

    matrix = new int*[size];

    for(i = 0;i < size;i++){
        matrix[i] = new int[size];
    }

    for(i = 0;i < size;i++){
        matrix[0][i] = v1[i];
    }

    for(i = 0;i < size;i++){
        matrix[1][i] = v2[i];
    }

    for(i = 0;i < size;i++){
        matrix[2][i] = v3[i];
    }

    for(i = 0;i < size;i++){
        matrix[3][i] = v4[i];
    }

    for(i = 0;i < size;i++){
        matrix[4][i] = v5[i];
    }

    graph.createGraph(matrix, size, size);

    cout << "Graph is: " << endl << endl;
    graph.print();

    cout << endl << "Breadth First Traversal of Graph: ";

    graph.bfs();

    cout << endl;

    cout << "Depth First Traversal of Graph: "; 
    
    graph.depthFirstTraversal();

    cout << endl << endl;

    cout << "Weighted Graph" << endl << endl;

    WeightedGraph wgraph(size);
    wgraph.createWeightedGraph(matrix, size, size);

    wgraph.shortestPath(0);

    cout << "Shortest Path from vertex 0 is: " << endl << endl;
    wgraph.printShortestPath();


    return 0;
}