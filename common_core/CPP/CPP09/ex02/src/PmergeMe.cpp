#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->_deq = other._deq;
    this->_vec = other._vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_deq = other._deq;
        this->_vec = other._vec;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositive(const std::string& str) const {
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true; 
}

void PmergeMe::parseArgs(int argc, char **argv) {
    if (argc < 2)
        throw PmergeMe::NoArgs();
    for (int i = 1; i < argc; i++) {
        if (!isPositive(argv[i]))
            throw PmergeMe::IntNegative();
        int nb = std::atoi(argv[i]);
        _vec.push_back(nb);
        _deq.push_back(nb);
    }
}

void PmergeMe::vectorRecursive(std::vector<int>& vec, size_t left, size_t right) {
    if (left >= right)
        return;

    std::vector<int> smallest, largest;
    bool hasOdd = ((right - left + 1) % 2 != 0);
    int oddValue = 0;

    size_t i = left;
    while (i + 1 <= right) {
        int first = vec[i];
        int second = vec[i + 1];
        if (first <= second) {
            smallest.push_back(first);
            largest.push_back(second);
        } else {
            smallest.push_back(second);
            largest.push_back(first);
        }
        i += 2;
    }

    if (hasOdd)
        oddValue = vec[right];

    if (largest.size() > 1)
        vectorRecursive(largest, 0, largest.size() - 1);

    vec.clear();
    for (size_t j = 0; j < largest.size(); ++j)
        vec.push_back(largest[j]);

    for (size_t j = 0; j < smallest.size(); ++j)
        insertVector(vec, smallest[j]);

    if (hasOdd)
        insertVector(vec, oddValue);
}

void PmergeMe::insertVector(std::vector<int>& vec, int value) {
    size_t i = 0;
    while (i < vec.size() && vec[i] < value)
        i++;
    vec.insert(vec.begin() + i, value);
}

void PmergeMe::mergeInsertVector(std::vector<int>& vec) {
    if (vec.size() < 2)
        return;
    vectorRecursive(vec, 0, vec.size() - 1);
}

void PmergeMe::insertDeque(std::deque<int>& deq, int value) {
    size_t i = 0;

    while (i < deq.size() && deq[i] < value)
        i++;
    deq.insert(deq.begin() + i, value);
}

void PmergeMe::mergeInsertDeque(std::deque<int>& deq) {
    if (deq.size() < 2)
        return;
    dequeRecursive(deq, 0, deq.size() - 1);
}

void PmergeMe::dequeRecursive(std::deque<int>& deq, size_t left, size_t right) {
    if (left >= right)
        return;

    std::deque<int> smallest, largest;
    bool hasOdd = ((right - left + 1) % 2 != 0);
    int oddValue = 0;

    size_t i = left;
    while (i + 1 <= right) {
        int first = deq[i];
        int second = deq[i + 1];
        if (first <= second) {
            smallest.push_back(first);
            largest.push_back(second);
        } else {
            smallest.push_back(second);
            largest.push_back(first);
        }
        i += 2;
    }

    if (hasOdd)
        oddValue = deq[right];

    if (largest.size() > 1)
        dequeRecursive(largest, 0, largest.size() - 1);

    deq.clear();
    for (size_t j = 0; j < largest.size(); ++j)
        deq.push_back(largest[j]);

    for (size_t j = 0; j < smallest.size(); ++j)
        insertDeque(deq, smallest[j]);

    if (hasOdd)
        insertDeque(deq, oddValue);
}

void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
    
    clock_t start = clock();
    mergeInsertVector(_vec);
    clock_t end = clock();
    double timeVec = double(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    mergeInsertDeque(_deq);
    end = clock();
    double timeDeq = double(end - start) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque : " << timeDeq << " us" << std::endl;
}

const char *PmergeMe::IntNegative::what() const throw() {return "Error: negative are forbidden";}
const char *PmergeMe::NoArgs::what() const throw() {return "Error: usage : ./PmergeMe [...]";}
