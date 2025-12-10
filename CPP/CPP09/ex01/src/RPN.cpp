#include "RPN.hpp"
#include <iostream>
#include <cctype>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    this->_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isNumber(const std::string& token) const {
    if (token.size() == 1 && std::isdigit(token[0]))
        return true;
    return false;
}

bool RPN::isOperator(const std::string& token) const {
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

void RPN::applyOperator(const std::string& op) {
    if (_stack.size() < 2)
        throw RPN::StackOut();

    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    int result = 0;

    if (op == "+")
        result = a + b;
    else if (op == "-")
        result = a - b;
    else if (op == "*")
        result = a * b;
    else if (op == "/") {
        if (b == 0)
            throw RPN::DivByZero();
        result = a / b;
    }
    _stack.push(result);
}

int RPN::getResult(const std::string& str) {
    std::istringstream iss(str);
    std::string token;

    while (iss >> token) {
        if (isNumber(token))
            _stack.push(token[0] - '0');
        else if (isOperator(token))
            applyOperator(token);
        else
            throw RPN::InvalidChar();
    }

    if (_stack.size() != 1)
        throw RPN::StackOut();
    
    return _stack.top();
}

RPN::StackOut::StackOut() : std::out_of_range("Error") {}

const char *RPN::DivByZero::what() const throw() {return "Error";}
const char *RPN::InvalidChar::what() const throw() {return "Error";}
