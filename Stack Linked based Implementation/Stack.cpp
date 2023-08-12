#pragma once
#include<iostream>
#include "Stack.h"
#include "Node.h"
using namespace std;

template<class T>
Stack<T>::Stack(){
    this->top = NULL;
}

template<class T>
Stack<T>::Stack(const Stack<T> &list){
    this->top = NULL;
    copyStack(list);
}

template<class T>
void Stack<T>::initialize(){
    Node<T> *tmp;
    while(top!=NULL){
        tmp = this->top;
        this->top = this->top->next;
        delete tmp;
    }
}

template<class T>
bool Stack<T>::isEmpty(){
    return (this->top == NULL);
}

template<class T>
bool Stack<T>::isFull(){
    return false;
}

template<class T>
T Stack<T>::getTop(){
    if(top == 0){
        cout << "List is Empty" << endl; 
    }
    else{
        return this->top->element;
    }
}

template<class T>
void Stack<T>::push(T element){
    Node<T> *node;
    node = new Node<T>;
    node->element = element;
    node->next = top;
    top = node;
}

template<class T>
void Stack<T>::pop(){
    if(top == NULL){
        cout << "List is Empty" << endl; 
    }
    else{
        Node<T> *tmp;
        tmp = top;
        top = top->next;
        delete tmp;
    }
}

template<class T>
void Stack<T>::copyStack(const Stack<T> &list){
    if(this->top != NULL){
        initialize();
    }
    else if(list.top == NULL){
        this->top = NULL;
    }
    else{
        Node<T> *node;
        Node<T> *current;
        current = list.top;
        node = new Node<T>;
        node->element = current->element;
        node->next = NULL;
        top = node;
        current = current->next;

        while(current != NULL){
            node = new Node<T>;
            node->element = current->element;
            node->next = NULL;
            this->top->next = node;
            this->top = node;
            current = current->next;
        }
    }
}

template<class T>
Stack<T>::~Stack(){
    delete top;
}