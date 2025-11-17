#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::manageChar(const std::string& input) {
    char c = 0;
    size_t len = input.length();

}

void ScalarConverter::manageInt(const std::string& input) {

}

void ScalarConverter::manageFloat(const std::string& input) {
    
}

void ScalarConverter::manageDouble(const std::string& input) {

}

void ScalarConverter::manageSpecialCase(const std::string& input) {
    if (input == "nan" || input == "nanf") {        
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;        
    }
    else if (input == "+inf" || input == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;     
    }
    else if (input == "-inf" || input == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;  
    }
}

bool ScalarConverter::isChar(const std::string& input, size_t len) {
    if (input.length() == 1) {
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string& input, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (i == 0 && (input[i] == '-' || input[i] == '+')) {
            continue ;
        }
        else if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& input, size_t len) {
    
}

bool ScalarConverter::isDouble(const std::string& input, size_t len) {
    
}

bool ScalarConverter::isSpecialCase(const std::string& input) {
    if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff") {
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string& input) {
    if (input.empty()) {
        std::cerr << "Wrong input , enter a char , int , float or double please." << std::endl;
        return ;
    }

    size_t len = input.length();
    
    if (isSpecialCase(input)) {
        manageSpecialCase(input);
        return ;
    }
    else if (isChar(input, len)) {
        manageChar(input);
    }
    else if (isInt(input, len)) {
        manageInt(input);
    }
    else if (isFloat(input, len)) {
        manageFloat(input);
    }
    else if (isDouble(input, len)) {
        manageDouble(input);
    }
    else {
        std::cerr << "Wrong input , enter a char , int , float or double please." << std::endl;
    }
}
