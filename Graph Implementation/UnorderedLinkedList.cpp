#pragma once
#include "UnorderedLinkedList.h"
#include <cstddef>
using namespace std;


template <class T>
UnorderedLinkedList<T>::UnorderedLinkedList()
{

}


template <class T>
bool UnorderedLinkedList<T>::search(const T &element){
    bool found = false;
    Node<T> *current;
    current = this->head;
    while(current != NULL){
        if(current->element == element){
            found = true;
            break;
        }
        current = current->next;
    }

    return found;
}


template <class T>
void UnorderedLinkedList<T>::insertFirst(const T &element){
    Node<T> *node = new Node<T>();
    node->element = element;
    
    if(this->head == NULL){
        node->next = NULL;
        this->head = node;
        this->last = this->head;
    }
    else{
        node->next = this->head;
        this->head = node;
    }

    this->count++;
}


template <class T>
void UnorderedLinkedList<T>::insertLast(const T &element){
    Node<T> *node = new Node<T>();
    node->element = element;
    node->next = NULL;

    if(this->head == NULL){    
        this->head = node;
        this->last = node;
    }
    else{
        this->last->next = node;
        this->last = node;
    }

    this->count++;
}


template <class T>
void UnorderedLinkedList<T>::deleteNode(const T &element){
    if(this->head == NULL){
        cout << "List is Empty";
    }
    else if(this->head->element == element){
        Node<T> *current;
        current = this->head;
        this->head = this->head->next;
        delete current;
        this->count--;
    }
    else{
        
        bool found;
        Node<T> *current;
        Node<T> *previous;
        previous = this->head;
        current = this->head->next;
        
        while(current != NULL){
            if(current->element != element){
                previous = current;
                current = current->next; 
            }
            else{
                found = true;
                break;
            }
        }

        if(found){
            previous->next = current->next;
            
            if(current == this->last){
                this->last = previous;
            }

            delete current;
            this->count--;
        }
        else{
            cout << element << " is not in the list" << endl;
        }
    }
}
