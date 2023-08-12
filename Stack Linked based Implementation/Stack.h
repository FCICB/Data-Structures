#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Node.h"


template<class T>
class Stack{
public:  
    Stack();
    Stack(const Stack<T> &list);
    void initialize();
    bool isEmpty();
    bool isFull();
    void push(T element);
    void pop();
    T getTop();
    void copyStack(const Stack<T> &list);
    ~Stack();
private:
    Node<T> *top;
};

#include "Stack.cpp"

#endif // STACK_H_INCLUDED