#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"
#include <exception>

template <class T>
Array<T>::Array() {
    _size = 0;
}

template <class T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _size = n;
}

template <class T>
Array<T>::Array(const Array& other) {
    unsigned int len = other.size();
    _size = len;
    _array = new T[len];

    for (unsigned int i = 0; i < len; i++) {
        _array[i] = other._array[i];
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _array;
        unsigned int len = other.size();
        _size = len;
        _array = new T[len];
        for (unsigned int i = 0; i < len; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <class T>
Array<T>::~Array() {
    delete[] _array;
}

template <class T>
unsigned int Array<T>::size() const {
    return _size;
}

template <class T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

#endif