#include "Base.hpp"
#include <iostream>

void identify(Base *p) {
    A *Atest = dynamic_cast<A *>(p);
    B *Btest = dynamic_cast<B *>(p);
    C *Ctest = dynamic_cast<C *>(p);

    if (Atest) {
        std::cout << "The type of p is : \"A\"" << std::endl; 
    }
    else if (Btest) {
        std::cout << "The type of p is : \"B\"" << std::endl; 
    }
    else if (Ctest) {
        std::cout << "The type of p is : \"C\"" << std::endl; 
    }
    else {
        std::cout << "The type of p is different than A, B or C !" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "The type of p is : \"A\"" << std::endl; 
        return ;
    } catch (...) {}
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "The type of p is : \"B\"" << std::endl; 
        return ;
    } catch (...) {}
    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "The type of p is : \"C\"" << std::endl;
        return ;
    }
    catch (...) {
        std::cout << "The type of p is different than A, B or C !" << std::endl;
    }
}
