//
// Created by Nicole Vivier on 10/19/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSLISTNODE_H
#define INC_21F_FLIGHT_PLANNER_DSLISTNODE_H

template <typename T>
struct DSListNode{
    T data;
    DSListNode* next;
    DSListNode* previous;

    DSListNode() {
        this->next = nullptr;
        this->previous = nullptr;
    }

    DSListNode(const T& data) {
        this->data = data;
        this->next = nullptr;
        this->previous = nullptr;
    }
};
#endif //INC_21F_FLIGHT_PLANNER_DSLISTNODE_H
