#include <iostream>
#include <stdlib.h>
#include "node.h"
#include "State.h"
using namespace std;

int main() {
    State state;
    Node<int>* a = state.newNode(1);
    Node<int>* b = state.newNode(2);
    Node<int>* c = state.newNode(3);
    a->pushChild(c);
    Node<int>* d = state.newNode(4);
    Node<int>* e = state.newNode(5);
    e->pushChild(c);
    a->pushChild(e);

    Node<int>* f = state.newNode(6);
    Node<int>* g = state.newNode(7);
    e->pushChild(g);
    Node<int>* h = state.newNode(8);
    state.stack.print();

    cout << "Finish" << endl;

    return 0;
}