#pragma once
#include "Node.h"
using namespace std;

template <class T>
Node<T>::Node(T element){
    this->element = element;
    this->next = NULL;
}

