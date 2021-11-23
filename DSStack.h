//
// Created by Nicole Vivier on 10/22/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSSTACK_H
#define INC_21F_FLIGHT_PLANNER_DSSTACK_H

#include "DSLinkedList.h"
#include "DSListNode.h"

template<typename T>
class DSStack {
private:
    DSLinkedList<T> list;
public:
    void push(T);
    void pop();
    T& peek();
    bool isEmpty();
};
template<typename T>
void DSStack<T>::push(T arg) {
    list.append(arg);
}

template<typename T>
void DSStack<T>::pop() {
    list.removeTail();
}

template<typename T>
bool DSStack<T>::isEmpty() {
    if (list.getLength() == 0)
        return true;
    else
        return false;
}

template<typename T>
T& DSStack<T>::peek() {
    return list.getTail();
}

#endif //INC_21F_FLIGHT_PLANNER_DSSTACK_H
