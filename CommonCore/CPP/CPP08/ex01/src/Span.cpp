#include "Span.hpp"
#include <climits>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

Span::Span() {
    _array = new int[10];
    _size = 10;
    _fill_index = 0;
}

Span::Span(unsigned int N) {
    _array = new int[N];
    _size = N;
    _fill_index = 0;
}

Span::Span(const Span& other) {
    _size = other._size;
    _fill_index = other._fill_index;

    _array = new int[_size];
    for (int i = 0; i < _fill_index; i++) {
        _array[i] = other._array[i];
    }
}

Span::~Span() {
    delete[] _array;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _fill_index = other._fill_index;
        _array = new int[_size];
        for (int i = 0; i < _fill_index; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

void Span::addNumber(int nb) {
    if (_size == _fill_index) {
        throw Span::IndexIsOutOfRange();
    }
    _array[_fill_index] = nb;
    _fill_index++;
}

void Span::addMultipleNumbers(int nb) {
    if ((_fill_index + nb) > _size) {
        throw IndexIsOutOfRange();
    }
    srand(time(NULL));
    for (int i = 0; i < nb; i++) {
        _array[_fill_index++] = rand();
    }
}

int *Span::sortArray(int *array) {
    std::sort(array, array + _fill_index);
    return array;
}

int Span::min() const {
    int min = INT_MAX;

    for (int i = 0; i < _fill_index; i++) {
        if (_array[i] < min) {
            min = _array[i];
        }
    }
    return min;
}

int Span::max() const {
    int max = INT_MIN;

    for (int i = 0; i < _fill_index; i++) {
        if (_array[i] > max) {
            max = _array[i];
        }
    }
    return max;
}

void Span::shortestSpan() const {
    if (_fill_index  <= 1) {
        throw NoSpanFounded();
    }

    int *sorted = new int[_fill_index];
    for (int i = 0; i < _fill_index; i++) {
        sorted[i] = _array[i];
    }

    std::sort(sorted, sorted + _fill_index);
    
    int minSpan = INT_MAX;
    for (int i = 0; i < _fill_index - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan) {
            minSpan = diff;
        }
    }

    std::cout << "The shortest span is " << minSpan << std::endl;

    delete[] sorted;
}

void Span::longestSpan() const {
    if (_fill_index  <= 1) {
        throw NoSpanFounded();
    }

    int min = this->min();
    int max = this->max();

    std::cout << "The longest span is " << max - min << std::endl;
}

const char *Span::IndexIsOutOfRange::what() const throw() {
    return "Index is out of range !";
}

const char *Span::NoSpanFounded::what() const throw() {
    return "No span founded !";
}
