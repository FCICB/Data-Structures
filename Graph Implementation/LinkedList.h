#pragma once
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include "LinkedListIterator.h"
#include "Node.h"

template<class T>
class LinkedList{
public:
    LinkedList();
    LinkedList(const LinkedList<T> &list);
    void InitializeList();
    bool isEmpty() const;
    void print() const;
    int length() const;
    void destroyList();
    T front() const;
    T back() const;
    LinkedListIterator<T> begin();
    LinkedListIterator<T> end();
    virtual bool search(const T &element) = 0;
    virtual void insertFirst(const T &element) = 0;
    virtual void insertLast(const T &element) = 0;
    virtual void deleteNode(const T &element) = 0;
    void copyList(const LinkedList<T> &list);
    ~LinkedList();
protected:
    Node<T> *head;
    Node<T> *last;
    int count;
};

#include "LinkedList.cpp"

#endif // LINKEDLIST_H_INCLUDED