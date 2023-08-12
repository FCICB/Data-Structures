#pragma once
#include<iostream>
#include "Stack.h"
using namespace std;

template<class T>
Stack<T>::Stack(){
    this->top = 0;
    this->maxSize = 10;
    list = new T[this->maxSize];
}

template<class T>
Stack<T>::Stack(const Stack<T> &list){
    this->list = NULL;
    copyStack(list);
}

template<class T>
void Stack<T>::initialize(){
    this->top = 0;
}

template<class T>
bool Stack<T>::isEmpty(){
    return (this->top==0);
}

template<class T>
bool Stack<T>::isFull(){
    return (this->top==this->maxSize);
}

template<class T>
T Stack<T>::getTop(){
    if(top == 0){
        cout << "List is Empty" << endl; 
    }
    else{
        return list[top - 1];
    }
}

template<class T>
void Stack<T>::push(T element){
    if(top == maxSize){
        cout << "List is Full" << endl;
    }
    else{
        list[top] = element;
        top++;
    }
}

template<class T>
void Stack<T>::pop(){
    if(top == 0){
        cout << "List is Empty" << endl; 
    }
    else{
        top--;
    }
}

template<class T>
void Stack<T>::copyStack(const Stack<T> &list){

    delete [] this->list;
    this->maxSize = list.maxSize;
    this->top = list.top;

    this->list = new T[this->maxSize];

    for(int i = 0;i < maxSize;i++){
        this->list[i] = list.list[i];
    }
}

template<class T>
Stack<T>::~Stack(){
    delete [] list;
}




















