#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, const int len, F func) {
    if (!array || len <= 0) {
        return ;
    }
    for (int i = 0; i < len; i++) {
        func(array[i]);
    }
}

#endif
