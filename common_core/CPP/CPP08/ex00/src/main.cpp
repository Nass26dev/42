#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    try {
        std::cout << *easyfind(v, 40) << std::endl;
    }
    catch (NoOccurenceFound& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << *easyfind(v, 50) << std::endl;
    }
    catch (NoOccurenceFound& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << *easyfind(l, 2) << std::endl;
    }
    catch (NoOccurenceFound& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << *easyfind(l, 154) << std::endl;
    }
    catch (NoOccurenceFound& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
