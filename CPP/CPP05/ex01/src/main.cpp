#include "Bureaucrat.hpp"

int main() {
    Bureaucrat a;
    Bureaucrat b("Bob", 1);
    Bureaucrat c(a);
    Bureaucrat d("Bobby", 23);
    d = b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;    
    std::cout << c << std::endl;
    std::cout << d << std::endl;
    
    std::cout << std::endl;

    try {
        a.incrementGrade();
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;
    
    try {
        b.incrementGrade();
        std::cout << a << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat("Bob", 0);
    }
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat("Bob", 151);
    }
    catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}