#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<class T>
class Stack{
public:  
    Stack();
    Stack(const Stack<T> &list);
    void initialize();
    bool isEmpty();
    bool isFull();
    virtual void push(T element);
    virtual void pop();
    T getTop();
    void copyStack(const Stack<T> &list);
    virtual ~Stack();
protected:
    T *list;
    int top;
    int maxSize;
};

#include "Stack.cpp"


#endif // STACK_H_INCLUDED