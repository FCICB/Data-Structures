#pragma once
#include <iostream>
#include "Hashing.h"

using namespace std;

template<class T>
Hashing<T>::Hashing(int listSize){
    if(listSize > 0){
        this->size = 0;
        this->listSize = listSize;
        this->list = new T[listSize];
        this->listStatus = new int[listSize];

        for(int i = 0;i < listSize;i++){
            listStatus[i] = 0;
        }
    }
    else{
        cout << "size of list should be greater than zero" << endl; 
    }
}


template<class T>
int Hashing<T>::hash(int key){
    return key % this->listSize;
}


template<class T>
void Hashing<T>::insert(int key, T value){
    int index = hash(key);

    int i = 0;
    while(this->listStatus[index] == 1 && list[index] != value && i < this->listSize){
        index = (index + i*i) % this->listSize;
        i++;
    }

    if(listStatus[index] != 1){
        list[index] = value;
        this->listStatus[index] = 1;
        this->size++;
    }
    else if(list[index] == value){
        cout << "Duplicate values are not allowed" << endl;
    }
    else if(this->size == this->listSize){
        cout << "List is Full" << endl;
    }
}


template<class T>
void Hashing<T>::remove(int key, T value){
    int index = hash(key);
    int i = 0;
    int flag = 0;

    while(listStatus[index] != 0 && i < this->listSize){
        if(listStatus[index] == 1 && list[index] == value){
            listStatus[index] = -1;
            this->size--;
            flag = 1;
            break;
        }

        index = (index + i*i) % this->listSize;
        i++;
    }

    if(!flag){
        cout << "Element " << value <<  " doesn't exist" << endl; 
    }

}


template<class T>
bool Hashing<T>::search(int key, T value){
    int index = hash(key);
    int i = 0;

    while(listStatus[index] != 0 && i < this->listSize){
        if(listStatus[index] == 1 && list[index] == value){
            return true;
        }

        index = (index + i*i) % this->listSize;
        i++;
    }
    return false;
}

template<class T>
void Hashing<T>::print(){
    for(int i = 0;i < this->listSize;i++){
        if(this->listStatus[i] == 1){
            cout << this->list[i] << " ";
        }
    }
}

template<class T>
Hashing<T>::~Hashing(){
    delete[] list;
    delete[] listStatus;
}

















