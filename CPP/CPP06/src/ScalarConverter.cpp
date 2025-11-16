#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {}

ScalarConverter::~ScalarConverter() {}

void manageChar(const std::string &input) {
    char c;

    std::cout << "char: ";
    if (input.length() == 1) {
        c = input[0];
    }
    else {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (c < 32 || c >= 127) {
        std::cout << "Non displayable" << std::endl;
    }
    else {
        std::cout << "'" << c << "'" << std::endl;
    }
}

void manageInt(const std::string &input) {
    long long i;
    size_t len = input.length();
    
    std::cout << "int: " << std::endl;
    
    for (size_t j = 0; j < len; j++) {
        if (j == 0 && (input[j] == '+' || input[j] == '-')) {
            continue;
        }
        if (!isdigit(input[j])) {
            std::cout << "impossible" << std::endl;
            return;
        }
    }
    i = std::atoll(input.c_str());
    if (i > INT_MAX || i < INT_MIN) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << i << std::endl;
}

void manageFloat(const std::string &input) {
    
}

void manageDouble(const std::string &input) {

}

void ScalarConverter::convert(const std::string& input) {
    manageChar(input);
    manageInt(input);
    manageFloat(input);
    manageDouble(input);
}
