#pragma Once
#include<iostream>
#include "WeightedGraphType.h"

using namespace std;


WeightedGraph::WeightedGraph(int size)
                :Graph(size)
{
    weightedGraph = new int*[size];

    for(int i = 0;i < size;i++){
        weightedGraph[i] = new int[size];
    }

    weights = new int[size];
}

void WeightedGraph::createWeightedGraph(int **graph, int n, int m){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
           weightedGraph[i][j] = graph[i][j];
        }
    }
}

void WeightedGraph::shortestPath(int vertex){
    bool visited[verticesCount];

    for(int i = 0;i < this->verticesCount;i++){
        weights[i] = weightedGraph[vertex][i];
    }

    for(int i = 0;i < this->verticesCount;i++){
        visited[i] = false;
    }

    weights[vertex] = 0;
    visited[vertex] = true;

    for(int i = 0;i < verticesCount - 1;i++){

        int  min = INT16_MAX;
        int  minVertex;

        for(int j = 0;j < verticesCount;j++){
            if(weights[j] < min && !visited[j]){
                min = weights[j];
                minVertex = j;
            }
        }
    
        visited[minVertex] = true;
        
        for(int k = 0;k < verticesCount;k++){
            if(min + weightedGraph[minVertex][k] < weights[k]){
                weights[k] = min + weightedGraph[minVertex][k];
            }
        }
    }

}

void WeightedGraph::printShortestPath(){
    for(int i = 0;i < this->verticesCount;i++){
        cout << "vertex " << i << " " << weights[i] << endl;
    }
}

WeightedGraph::~WeightedGraph(){
    for(int i = 0;i < this->verticesCount;i++){
        delete [] weightedGraph[i];
    }

    delete [] weightedGraph;
    delete [] weights;
}















