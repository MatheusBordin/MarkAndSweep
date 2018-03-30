//
// Created by mabor on 30/03/2018.
//

#ifndef MARKANDSWEEP_NODE_H
#define MARKANDSWEEP_NODE_H

#include <vector>
using namespace std;

template <typename T>
class Node
{
public:
    Node<T>* next;
    Node<T>* previous;
    vector<Node<T>*>* children;
    int marked;
    T value;

    Node(): marked(0), children(new vector<Node<T>*>()) {}
    virtual ~Node() {
        delete children;
    }

    void pushChild(Node<int>* ptr) {
        children->push_back(ptr);
    }

    void popChild(Node<int>* ptr) {
        int index = 0;
        for(auto child : *children) {
            if(child == ptr) children->erase(children->begin() + index);
            index++;
        }
    }
};

#endif //MARKANDSWEEP_NODE_H
