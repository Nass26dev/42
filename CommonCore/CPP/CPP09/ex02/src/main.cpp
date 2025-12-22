#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
    try {
        PmergeMe sort;

        sort.parseArgs(argc, argv);
        sort.sortAndDisplay();
    }
    catch (PmergeMe::NoArgs& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (PmergeMe::IntNegative& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
