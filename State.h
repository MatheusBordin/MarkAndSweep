//
// Created by mabor on 30/03/2018.
//

#ifndef MARKANDSWEEP_STATE_H
#define MARKANDSWEEP_STATE_H

#include "node.h"
#include "Gc.h"
using namespace std;

class State: public Gc {
public:
    int totalMarked;
    int markedLevel;

    State(): totalMarked(0), markedLevel(0) {};

    void gc() {
        markedLevel++;
        if(markedLevel > 2)
            markedLevel = 1;

        totalMarked = 0;
        mark(stack.first);
        sweep();
    }

    void mark(Node<int> *ptr) {
        // If missing parameter ptr, return.
        if(!ptr)
            return;

        // Adjust markedLevel of node.
        if(ptr->marked > markedLevel)
            ptr->marked = 0;
        else if(ptr->marked == markedLevel)
            return;

        // If object is 'visible' push left then
        stack.toLeft(ptr);
        // Mark then (fix circular dependencie)
        ptr->marked = markedLevel;
        // Increment total 'visible' objects
        totalMarked++;

        for(auto child : *ptr->children) {
            mark(child);
        }
    }

    void sweep() {
        int totalRemoved = 0;
        Node<int>* previous;
        Node<int>* current;
        current = stack.last;
        int removedCount = stack.total - totalMarked;

        while(removedCount > 0 && current) {
            previous = current->previous;
            stack.pop(current);
            current = previous;
            totalRemoved++;
            removedCount--;
        }

        cout << "Total removed: " << totalRemoved << endl;
    }

};

#endif //MARKANDSWEEP_STATE_H
