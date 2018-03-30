//
// Created by mabor on 30/03/2018.
//

#ifndef MARKANDSWEEP_GC_H
#define MARKANDSWEEP_GC_H

#include "node.h"
#include "ldde.h"
using namespace std;

class Gc {
public:
    LDDE<int> stack;

    Gc(): maxSizeToRunGc(4) {};
    ~Gc() {};

    Node<int>* newNode(int value) {
        if(stack.total >= maxSizeToRunGc)
            gc();

        Node<int> *ptr = new Node<int>();
        ptr->value = value;

        stack.push(ptr);

        return ptr;
    }

protected:
    virtual void mark(Node<int> *ptr) = 0;
    virtual void sweep() = 0;
    virtual void gc() = 0;

    int maxSizeToRunGc;
};

#endif //MARKANDSWEEP_GC_H
