#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class Queue{
public:
    Queue(int size);
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
    T *list;
    int maxSize;
    int front;
    int rear;
    int counter;
};

#include "Queue.cpp"

#endif