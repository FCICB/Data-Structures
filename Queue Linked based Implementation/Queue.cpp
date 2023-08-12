#pragma once
#include<iostream>
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue(){
    this->front = NULL;
    this->rear = NULL;
}


template <class T>
Queue<T>::Queue(const Queue<T> &list){
    this->front = NULL;
    copy(list);
}


template <class T>
void Queue<T>::initialize(){
    Node<T> *node;

    while(front != NULL){
        node = front;
        front = front->next;
        delete node;
    }
    this->rear = NULL;
}


template <class T>
bool Queue<T>::isEmpty(){
    return (front == NULL);
}


template <class T>
bool Queue<T>::isFull(){
    return false;
}


template <class T>
T Queue<T>::getFront(){
    if(!isEmpty()){
        return front->element;
    }
    else{
        cout << "List is Empty" << endl;
    }
}


template <class T>
T Queue<T>::getBack(){
    if(!isEmpty()){
        return rear->element;
    }
    else{
        cout << "List is Empty" << endl;
    }
}


template <class T>
void Queue<T>::enqueue(T element){
    if(isFull()){
        cout << "List is Full" << endl;
    }
    else{
        Node<T> *node;
        node = new Node<T>;
        node->element = element;
        node->next = NULL;
        if(front == NULL){
            front = node;
            rear = node;
        }
        else{
            rear->next = node;
            rear = node;
        }
    }
}


template <class T>
void Queue<T>::dequeue(){
    if(isEmpty()){
        cout << "List is Empty" << endl;
    }
    else{
        Node<T> *node;

        node = front;
        front = front->next;

        if(front == NULL){
            rear = NULL;
        }

        delete node;
    }
}


template <class T>
void Queue<T>::copy(const Queue<T> &list){
    if(front != NULL){
        initialize();
    }
    else if(list.front == NULL){
        front = NULL;
        rear = NULL;
    }
    else{
        Node<T> *node;
        Node<T> *current;
        
        node = new Node<T>;
        current = list.front;

        node->element = current->element;
        node->next = NULL;
        front = node;
        rear = node;
        current = current->next;

        while(current != NULL){
            node = new Node<T>;
            node->element = current->element;
            node->next = NULL;

            rear->next = node;
            rear = node;
            current = current->next;
        }
    }
}


template <class T>
Queue<T>::~Queue(){
    initialize();
}





