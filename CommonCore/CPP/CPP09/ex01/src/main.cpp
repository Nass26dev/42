#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        std::cout << rpn.getResult(argv[1]) << std::endl;
    }
    catch (RPN::StackOut& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (RPN::DivByZero& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    catch (RPN::InvalidChar& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
