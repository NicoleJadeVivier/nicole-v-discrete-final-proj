//
// Created by Nicole Vivier on 9/14/2021.
//

#ifndef INC_21F_PA02_DSVECTOR_H
#define INC_21F_PA02_DSVECTOR_H
#include <iostream>

template <typename T>
class DSVector {
private:
    int cap; //capacity
    int size;
    T* data;
    void resize();

public:
    //constructors
    DSVector();
    DSVector(int theSize);
    DSVector(const DSVector<T>&);
    ~DSVector();

    //overloaded assignment operator
    DSVector<T>& operator= (const DSVector<T>&);

    void push_back(const T&);
    T& operator[] (int location) const;
    T& at(int);

    //returns the size
    int getLength()const;
    //returns the capacity
    int getCapacity()const;

    ////removefucntion
    void remove(int);
    ////iterator function
    void sort();
    int find(T value);
    void print();
};

template<typename T>
DSVector<T>::DSVector() {
    data = new T[10];
    cap = 10;
    size = 0;
}

template<typename T>
DSVector<T>::DSVector(int theSize) {
    if (theSize > 0) {
        data = new T[theSize];
        cap = theSize;
        size = 0;
    } else {
        throw std::runtime_error("Overloaded constructor: Vector size must be above zero");
    }
}
template<typename T>
DSVector<T>::DSVector(const DSVector<T> &arg) {
    cap = arg.getCapacity();
    size = arg.getLength();
    data = new T[arg.cap];
    for (int i = 0; i < arg.size; i++) {
        data[i] = arg[i];
    }
}


template<typename T>
void DSVector<T>::push_back(const T& arg) {
    if (size == cap) {
        resize();
    }
        data[size] = arg;
        size++;
}

template<typename T>
void DSVector<T>::resize() {
    T* temp = new T[cap * 2];
    for (int i = 0; i < cap; i++) {
        temp[i] = data[i];
    }
    cap = cap * 2;
    delete[] data;
    data = temp;

}

template<typename T>
T &DSVector<T>::operator[](int location)const  {
    if (location >= 0 && location < size) {
        return data[location];
    } else {
        throw std::runtime_error("Operator []: Desired vector index out of bounds");
    }
}

template<typename T>
T &DSVector<T>::at(int location) {
    if (location >= 0 && location < size) {
        return data[location];
    } else {
        throw std::runtime_error("Function at(): Desired vector index out of bounds");
    }
}

template<typename T>
int DSVector<T>::getLength()const {
    return this->size;
}

template<typename T>
int DSVector<T>::getCapacity()const {
    return this->cap;
}

template<typename T>
DSVector<T>::~DSVector() {
    delete[] data;
}

template<typename T>
DSVector<T> &DSVector<T>::operator=(const DSVector<T>& arg) {
    if (this != &arg) {
        delete[] data;
        cap = arg.getCapacity();
        size = arg.getLength();
        data = new T[arg.cap];
        for (int i = 0; i < arg.size; i++) {
            data[i] = arg[i];
        }
    }
    return *this;
}

//https://github.com/CS1342-Spring2021/Lecture-Materials/blob/master/Chapter09/selection_sort.cpp
template<typename T>
void DSVector<T>::sort() {
    int indexSmallest;

    for (int i = 0; i < this->size - 1; ++i) {
        indexSmallest = i;
        for (int j = i + 1; j < this->size; ++j) {
            if (data[j] < data[indexSmallest]) {
                indexSmallest = j;
            }
        }

        T temp;
        temp = data[i];
        data[i] = data[indexSmallest];
        data[indexSmallest] = temp;
    }
}


template<typename T>
int DSVector<T>::find(T value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void DSVector<T>::remove(int location) {
    T* temp = new T[this->size - 1];
    if (location >= 0 && location < size) {
        for (int i = 0; i < location; i++) {
            temp[i] = data[i];
        }

        int j = location;
        for (int i = location + 1; i < size; i++) {
           temp[j] = data[i];
           j++;
        }

        delete[] data;
        this->data = temp;
        this->size -= 1;
    } else {
        throw std::runtime_error("DSVector Remove(): Desired vector index out of bounds");
    }
}

template<typename T>
void DSVector<T>::print() {
    for(int i = 0; i < size; i++) {
        std::cout << data[i] << std::endl;
    }
}


#endif //INC_21F_PA02_DSVECTOR_H
