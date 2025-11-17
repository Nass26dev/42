#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <limits>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::manageChar(const std::string& input) {
    char c = input[0];
    
    if (isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    }
    else {
        std::cout << "char: non displayable" << std::endl;
    }
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::manageInt(const std::string& input) {
    int i = std::atoi(input.c_str());

    if (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max()) {
        char c = static_cast<char>(i);
        if (isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else {
            std::cout << "char: non displayable" << std::endl;
        }
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::manageFloat(const std::string& input) {
    float f = std::strtof(input.c_str(), NULL);

    if (f >= std::numeric_limits<char>::min() && f <= std::numeric_limits<char>::max()) {
        char c = static_cast<char>(f);
        if (isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else {
            std::cout << "char: non displayable" << std::endl;
        }
    }
    else {
        std::cout << "char: " << "impossible" << std::endl;
    }
    if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max()) {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    else {
        std::cout << "int: impossible" << std::endl;
    }
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::manageDouble(const std::string& input) {
    double d = std::strtod(input.c_str(), NULL);

    if (d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max()) {
        char c = static_cast<char>(d);
        if (isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else {
            std::cout << "char: non displayable" << std::endl;
        }
    }
    else {
        std::cout << "char: impossible" << std::endl;
    }
    if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()) {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    else {
        std::cout << "int: impossible" << std::endl;
    }
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
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
    if (len == 1 && !isdigit(input[0])) {
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string& input, size_t len) {
    if (len > 11) {
        return false;
    }
    for (size_t i = 0; i < len; i++) {
        if (i == 0 && (input[i] == '-' || input[i] == '+')) {
            continue ;
        }
        else if (!isdigit(input[i])) {
            return false;
        }
    }
    long long int i = std::atoll(input.c_str());
    if (i > INT_MAX || i < INT_MIN) {
        return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& input, size_t len) {
    if (input[len - 1] != 'f') {
        return false;
    }
    if (len > 1 && (input[0] == '.' || (input[0] == '-' && input[1] == '.') || (input[0] == '+' && input[1] == '.'))) {
        return false;
    }
    int dot_count = 0;
    for (size_t i = 0; i < (len - 1); i++) {
        if (i == 0 && (input[i] == '-' || input[i] == '+')) {
            continue ;
        }
        else if (input[i] == '.') {
            dot_count++;
            if (dot_count > 1) {
                return false;
            }
        }
        else if (!isdigit(input[i]) && input[i] != '.') {
            return false;
        }
    }
    if (input[len - 2] == '.') {
        return false;
    }
    return true;
}

bool ScalarConverter::isDouble(const std::string& input, size_t len) {
    int dot_count = 0;
    
    if (len > 1 && (input[0] == '.' || (input[0] == '-' && input[1] == '.') || (input[0] == '+' && input[1] == '.'))) {
        return false;
    }
    for (size_t i = 0; i < len; i++) {
        if (i == 0 && (input[i] == '-' || input[i] == '+')) {
            continue;
        }
        else if (input[i] == '.') {
            dot_count++;
            if (dot_count > 1)
                return false;
        }
        else if (!isdigit(input[i])) {
            return false;
        }
    }
    if (input[len - 1] == '.') {    
        return false;
    }
    return true;
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
