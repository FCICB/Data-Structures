#pragma once
#include<iostream>
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue(int size){
    this->maxSize = size;
    this->list = new T[maxSize];
    this->front = 0;
    this->rear = maxSize - 1;
    this->counter = 0;
}


template <class T>
Queue<T>::Queue(const Queue<T> &list){
    this->list = NULL;
    copy(list);
}


template <class T>
void Queue<T>::initialize(){
    this->front = 0;
    this->rear = this->maxSize -1;
    this->counter = 0;
}


template <class T>
bool Queue<T>::isEmpty(){
    return (counter == 0);
}


template <class T>
bool Queue<T>::isFull(){
    return (counter == maxSize);
}


template <class T>
T Queue<T>::getFront(){
    if(!isEmpty()){
        return this->list[front];
    }
    else{
        cout << "List is Empty" << endl;
    }
}


template <class T>
T Queue<T>::getBack(){
    if(!isEmpty()){
        return this->list[this->rear];
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
        rear = (rear + 1) % this->maxSize;
        list[rear] = element;
        counter++;
    }
}


template <class T>
void Queue<T>::dequeue(){
    if(isEmpty()){
        cout << "List is Empty" << endl;
    }
    else{
        front = (front + 1) % this->maxSize;
        counter--;
    }
}


template <class T>
void Queue<T>::copy(const Queue<T> &list){
    delete [] this->list;
    this->maxSize = list.maxSize;
    this->list = new T[this->maxSize];
    this->front = list.front;
    this->rear = list.rear;
    this->counter = list.counter;

    for(int i = 0;i < maxSize;i++){
        this->list[i] = list.list[i];
    }
}


template <class T>
Queue<T>::~Queue(){
    delete [] list;
}





















