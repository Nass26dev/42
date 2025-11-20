#include "iter.hpp"

void square(int& n) {
    n = n * n;
}

void incrementByOne(size_t& n) {
    n = n + 1;
}

void printConst(const size_t n) {
    std::cout << n << " ";
}

void print(int n) {
    std::cout << n << " ";
}


int main() {
    int int_array[5] = {1,2,3,4,5};
    size_t size_t_array[5] = {1,2,3,4,5};

    ::iter(int_array, 5, square);
    ::iter(size_t_array, 5, incrementByOne);
    ::iter(int_array, 5, print);
    std::cout << std::endl;
    ::iter(size_t_array, 5, printConst);
    return (0);
}
