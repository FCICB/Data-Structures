#pragma Once
#include "Graph.h"
#include "Queue.h"
#include<iostream>
using namespace std;


Graph::Graph(int size){
    this->verticesCount = size;
    this->graph = new UnorderedLinkedList<int>[size];
}


void Graph::createGraph(int **graph, int n, int m){
    for(int i = 0;i < n;i++){
        for(int j = 1;j < m;j++){
            if(graph[i][j] < INT32_MAX){
                this->graph[i].insertLast(j);
            }
        }
    }
}

void Graph::clear(){
    for(int i = 0;i < verticesCount;i++){
        graph[i].destroyList();
    }

    verticesCount = 0;
}

bool Graph::isEmpty(){
    return (verticesCount == 0);
}

void Graph::print(){
    for(int i = 0;i < verticesCount;i++){
        if(!graph[i].isEmpty()){
            cout << i << " : ";
            graph[i].print();
        }
    }
}

Graph::~Graph(){
    this->clear();
}


void Graph::depthFirstTraversal(){
    bool visited[verticesCount];

    for(int i = 0;i < verticesCount;i++){
        visited[i] = false;
    }

    for(int i = 0;i < verticesCount;i++){
        if(!visited[i]){
            dfs(i, visited);   
        }
    }
}


void Graph::dfs(int vertex, bool visited[]){
    visited[vertex] = true;
    cout << vertex << " ";

    LinkedListIterator<int> it;

    for(it = graph[vertex].begin(); it != graph[vertex].end();++it){
        int adj = *it;
        
        if(!visited[adj]){
            dfs(adj, visited);
        }

    }
}


void Graph::bfs(){
    bool visited[verticesCount];
    Queue<int>queue(verticesCount * 2);

    for(int i = 0;i < this->verticesCount;i++){
        visited[i] = false;
    }

    for(int i = 0;i < verticesCount;i++){
        if(!visited[i]){
            queue.enqueue(i);
            visited[i] = true;
            cout << i << " ";
            
            while(!queue.isEmpty()){
                int vertex = queue.getFront();
                queue.dequeue();

                LinkedListIterator<int> it;
                for(it = graph[vertex].begin();it != graph[vertex].end();++it){
                    if(!visited[*it]){
                        visited[*it] = true;
                        queue.enqueue(*it);
                        cout << *it << " ";
                    }
                }
            }
        }
    }
}

