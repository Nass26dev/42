#include "Base.hpp"
#include <iostream>

int main() {
    Base *one = generate();
    Base *two = generate();
    Base *three = generate();

    identify(one);
    identify(two);
    identify(three);

    std::cout << std::endl;

    identify(*one);
    identify(*two);
    identify(*three);

    delete one; delete two; delete three;
}
