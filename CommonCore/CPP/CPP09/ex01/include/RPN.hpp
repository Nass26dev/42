#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
    private:
        std::stack<int> _stack;
        
        bool isNumber(const std::string& token) const;
        bool isOperator(const std::string& token) const;
        void applyOperator(const std::string& op);
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        int getResult(const std::string& str);
        class StackOut : public std::out_of_range {
            public:
                StackOut();
        };
        class DivByZero : public std::exception {
            public:
                const char *what() const throw();
        };
        class InvalidChar : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif