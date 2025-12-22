#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include <algorithm>
#include <iostream>
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int to_find) {
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end()) {
        throw NoOccurenceFound();
    }
    return it;
}

#endif
