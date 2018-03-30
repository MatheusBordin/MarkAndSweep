//
// Created by mabor on 30/03/2018.
//

#ifndef MARKANDSWEEP_LDDE_H
#define MARKANDSWEEP_LDDE_H

#include <iostream>
#include "node.h"
using namespace std;

template <typename T>
class LDDE {
public:
    Node<T>* first;
    Node<T>* last;
    int total;

    LDDE(): first(nullptr), last(nullptr), total(0){}

    virtual ~LDDE(){
        Node<T>* ptrCurrent = first;
        Node<T>* ptrnext = nullptr;

        while(ptrCurrent){
            ptrnext = ptrCurrent->next;
            delete ptrCurrent;
            ptrCurrent = ptrnext;
        }

        total = 0;
        first = nullptr;
        last = nullptr;
    }

    bool push(Node<T>* ptrNew){

        T value = ptrNew->value;

        if(!ptrNew)
            return false;

        ptrNew->previous = nullptr;
        ptrNew->next = nullptr;

        Node<T>* ptrCurrent = first;
        Node<T>* ptrPrevious = nullptr;

        while(ptrCurrent && ptrCurrent->value < value){
            ptrPrevious = ptrCurrent;
            ptrCurrent = ptrCurrent->next;
        }

        ptrNew->next = ptrCurrent;

        if(ptrPrevious)
            ptrPrevious->next = ptrNew;
        else
            first = ptrNew;

        if(ptrCurrent)
            ptrCurrent->previous = ptrNew;
        else
            last = ptrNew;

        ptrNew->previous = ptrPrevious;

        total++;
        return true;
    }

    Node<T>* search(T value){
        Node<T>* current = first;

        while (current && current->value <= value){
            if(current->value == value)
                return current;

            current = current->next;
        }
        return nullptr;
    }

    bool pop(Node<T>* node){
        if(!node)
            return false;

        if(!node->previous)
            first = node->next;
        else
            node->previous->next = node->next;

        if(!node->next)
            last = node->previous;
        else
            node->next->previous = node->previous;

        delete node;
        total--;
        return true;
    }

    void print(){
        Node<T>* current = first;

        while(current){
            cout<<current->value<<' ';
            current = current->next;
        }

        cout<<endl;
    }

    void toLeft(Node<T>* node) {
        if(node == first)
            return;

        if(node->previous)
            node->previous->next = node->next;

        if(node->next)
            node->next->previous = node->previous;
        else
            last = node->previous;

        node->next = first->next;
        node->previous = first;

        first->next->previous = node;
        first->next = node;
    }
};


#endif //MARKANDSWEEP_LDDE_H
