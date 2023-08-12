#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "Node.h"

template <class T>
class Queue{
public:
    Queue();
    Queue(const Queue<T> &list);
    void initialize();
    bool isEmpty();
    bool isFull();
    T getFront();
    T getBack();
    void enqueue(T element);
    void dequeue();
    void copy(const Queue<T> &list);
    ~Queue();
private:
    Node<T> *front;
    Node<T> *rear;
};

#include "Queue.cpp"

#endif