#pragma once
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template<class T>
struct Node{
    T element;
    Node<T> *next;
};

#endif // NODE_H_INCLUDED

