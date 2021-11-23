//
// Created by Nicole Vivier on 11/22/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#include "DSListNode.h"
#include <iostream>

template<typename T>
class DSLinkedList {
private:
    int length;
    DSListNode<T> *head;
    DSListNode<T> *tail;
    DSListNode<T> *current;

public:
    DSLinkedList();
    DSLinkedList(const DSLinkedList<T>&);
    ~DSLinkedList();

    DSLinkedList<T>& operator= (const DSLinkedList<T>&);

    void prepend(const T& arg);
    void setFront(const T& arg);
    void append(const T& arg);

    void print();
    void printReverse();

    T& getHead();
    T& getTail();
    int getLength();

    //iterator functions
    bool isEmpty();
    bool hasNext();
    bool currAtNull();
    void next();
    T& get_curr_value();
    void set_front();
    void removeTail();
};

template<typename T>
DSLinkedList<T>::DSLinkedList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;

    length = 0;
}

template<typename T>
DSLinkedList<T>::DSLinkedList(const DSLinkedList<T> &arg) {

    this->head = nullptr;
    this->tail = nullptr;
    this->current = nullptr;

    DSListNode<T> *curr = arg.head;
    while(curr != nullptr) {
        append(curr->data);
        curr = curr->next;
    }
    this->length = arg.length;
}

template<typename T>
DSLinkedList<T>& DSLinkedList<T>:: operator= (const DSLinkedList<T> &arg) {
    if (this != &arg) {
        while (this->head != nullptr) {
            this->removeTail();
        }

        this->head = nullptr;
        this->tail = nullptr;
        this->current = nullptr;
        this->length = 0;

        DSListNode<T> *curr = arg.head;
        while(curr != nullptr) {
            append(curr->data);
            curr = curr->next;
        }

        this->length = arg.length;
    }
    return *this;
}

template<typename T>
void DSLinkedList<T>::append(const T& arg) {
    if (this->head == nullptr) {
        setFront(arg);
    } else {
        DSListNode<T> *newNode = new DSListNode<T>(arg);

        this->tail->next = newNode;
        newNode->previous = this->tail;
        newNode->next = nullptr;
        this->tail = newNode;
    }
    length = length + 1;
}

template<typename T>
void DSLinkedList<T>::print() {
    if (this->head == nullptr) {
        std::cout << "list is empty" << std::endl;
        return;
    }
    DSListNode<T> *temp = this->head;
    while(temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

template<typename T>
DSLinkedList<T>::~DSLinkedList() {
    DSListNode<T> *curr = this->head;
    DSListNode<T> *next;

    while(curr != nullptr) {
        next = curr->next;
        delete curr;
        curr = next;
    }
    this->head = this->tail = nullptr;
}

template<typename T>
int DSLinkedList<T>::getLength() {
    return length;
}

template<typename T>
T& DSLinkedList<T>::getHead() {
    if (head != nullptr)
        return head->data;
    else
        throw std::runtime_error("DSLinkedList getHead(): Head is set to nullptr");
}

template<typename T>
void DSLinkedList<T>::setFront(const T& arg) {
    DSListNode<T> *newNode = new DSListNode<T>(arg);

    newNode->next = nullptr;
    newNode->previous = nullptr;
    this->head = newNode;
    this->tail = newNode;
}

template<typename T>
T& DSLinkedList<T>::getTail() {
    if (tail != nullptr)
        return tail->data;
    else
        throw std::runtime_error("DSLinkedList getTail(): Tail is set to nullptr");
}

template<typename T>
void DSLinkedList<T>::prepend(const T& arg) {
    if (this->head == nullptr) {
        setFront(arg);
    } else {
        DSListNode<T> *newNode = new DSListNode<T>(arg);

        newNode->next = this->head;
        newNode->previous = nullptr;
        this->head->previous = newNode;
        this->head = newNode;
    }
    length = length + 1;
}

template<typename T>
void DSLinkedList<T>::printReverse() {
    if (this->head == nullptr) {
        std::cout << "list is empty" << std::endl;
        return;
    }
    DSListNode<T> *curr = this->tail;
    while (curr != nullptr) {
        std::cout << curr->data << std::endl;
        curr = curr->previous;
    }
}

template<typename T>
bool DSLinkedList<T>::isEmpty() {
    if (this->head == nullptr)
        return true;
    else
        return false;
}

template<typename T>
bool DSLinkedList<T>::hasNext() {
    if (current == nullptr) {
        return false;
    } else if (this->current->next == nullptr)
        return false;
    else
        return true;
}

template<typename T>
void DSLinkedList<T>::set_front() {
    this->current = this->head;
}

template<typename T>
void DSLinkedList<T>::next() {
    if (current == nullptr) {
        throw std::runtime_error("DSLinkedList next(): current is already nullptr");
    }
    else
        this->current = current->next;
}

template<typename T>
void DSLinkedList<T>::removeTail() {
    if (this->head == nullptr)
        return;
    else if (length == 1) {
        DSListNode<T> *temp = this->head;
        this->head = nullptr;
        this->tail = nullptr;
        delete temp;
        length = length - 1;
    }
    else {
        DSListNode<T> *temp = this->tail;
        this->tail = this->tail->previous;
        this->tail->next = nullptr;
        delete temp;
        length = length - 1;
    }
}

template<typename T>
T& DSLinkedList<T>::get_curr_value() {
    if (current != nullptr)
        return current->data;
    else
        throw std::runtime_error("DSLinkedList get_curr_value(): cannot return nullptr");
}

template<typename T>
bool DSLinkedList<T>::currAtNull() {
    if (this->current == nullptr)
        return true;
    else
        return false;
}

#endif //INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
