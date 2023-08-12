#pragma once
#ifndef UNORDEREDLINKEDLIST_H_INCLUDED
#define UNORDEREDLINKEDLIST_H_INCLUDED

#include "LinkedList.h"
#include "LinkedListIterator.h"

template<class T>
class UnorderedLinkedList:public LinkedList<T>{
public: 
    UnorderedLinkedList();
    bool search(const T &element);
    void insertFirst(const T &element);
    void insertLast(const T &element);
    void deleteNode(const T &element);
};

#include "UnorderedLinkedList.cpp"

#endif // UNORDEREDLINKEDLIST_H_INCLUDED