#ifndef LINKEDLISTITERATOR_H_INCLUDED
#define LINKEDLISTITERATOR_H_INCLUDED
#include "Node.h"
#pragma once
using namespace std;



template<class T>
class LinkedListIterator{
public:
    LinkedListIterator();
    LinkedListIterator(Node<T> *node);
    T operator*();
    LinkedListIterator<T> operator++();
    bool operator==(const LinkedListIterator<T> &it);
    bool operator!=(const LinkedListIterator<T> &it);
private:
    Node<T> *current;
};

#include "LinkedListIterator.cpp"

#endif // LINKEDLISTITERATOR_H_INCLUDED