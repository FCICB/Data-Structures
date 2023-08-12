#pragma once
#include "LinkedList.h"
#include <iostream>
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
    this->last = NULL;
    this->count = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){
    this->head = NULL;
    copyList(list);
}

template <class T>
void LinkedList<T>::InitializeList(){
    destroyList();
}

template <class T>
bool LinkedList<T>::isEmpty() const{
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}


template <class T>
void LinkedList<T>::print() const{
    Node<T> *current;
    current = head;

    while(current != NULL){
        cout << current->element << " ";
        current = current->next;
    }
    cout << endl;
}


template <class T>
int LinkedList<T>::length() const{
    return count;
}


template <class T>
void LinkedList<T>::destroyList(){
    Node<T> *current;
    while(head != NULL){
        current = head;
        head = head->next;
        delete current;
    }
    last = NULL;
    count = 0;
}


template <class T>
T LinkedList<T>::front() const{
    if(head != NULL){
        return head->element;
    }
    else{
        cout << "List is Empty" << endl;
    }
}


template <class T>
T LinkedList<T>::back() const{
    if(last != NULL){
        return last->element;
    }
    else{
        cout << "List is Empty" << endl;
    }
}


template <class T>
void LinkedList<T>::copyList(const LinkedList<T> &list){
    if(head != NULL){
        destroyList();
    }
    if(list.head == NULL){
        head = NULL;
        last = NULL;
        count = 0;
    }
    else{
        Node<T> *current;
        Node<T> *node;
        node = new Node<T>;
        current = list.head;
        head = node;
        head->element = current->element;
        head->next = NULL;
        last = head;
        current = current->next;

        while(current != NULL){
            node = new Node<T>; 
            node->element = current->element;
            node->next = NULL;
            last->next = node;
            last = node;
            current = current->next;
        }
    }
}


template <class T>
LinkedListIterator<T> LinkedList<T>::begin(){
    LinkedListIterator<T> it(head);
    return it;
}

template <class T>
LinkedListIterator<T> LinkedList<T>::end(){
    LinkedListIterator<T> it(NULL);
    return it;
}


template <class T>
LinkedList<T>::~LinkedList(){
    destroyList();
}



















