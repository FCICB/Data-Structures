#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

template<class T>
class Hashing{
public:
    Hashing(int listSize);
    void insert(int key, T value);
    void remove(int key, T value);
    bool search(int key, T value);
    void print();
    ~Hashing();
private:
    T *list;
    int *listStatus;
    int size;
    int listSize;
    int hash(int key);
};

#include "Hashing.cpp"

#endif
