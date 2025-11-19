#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, const int len, T& (*func)(T& array_element)) {
    if (!array || len <= 0) {
        return ;
    }
    for (int i = 0; i < len; i++) {
        array[i] = func(array[i]);
    }    
}

#endif
