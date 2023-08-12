#pragma once
#include "LinkedListIterator.h"
#include <cstddef>
using namespace std;

template <class T>
LinkedListIterator<T>::LinkedListIterator(){
    current = NULL;
}

template <class T>
LinkedListIterator<T>::LinkedListIterator(Node<T> *node){
    current = node;
}

template<class T>
T LinkedListIterator<T>::operator*(){
    return this->current->element;
}

template<class T>
LinkedListIterator<T> LinkedListIterator<T>::operator++(){
    this->current = this->current->next;
    return *this;
}

template<class T>
bool LinkedListIterator<T>::operator==(const LinkedListIterator<T> &it){
    if(this->current == it.current){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool LinkedListIterator<T>::operator!=(const LinkedListIterator<T> &it){
    if(this->current != it.current){
        return true;
    }
    else{
        return false;
    }
}


