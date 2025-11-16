#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        Form a;
        Form b("Form 2", 1, 1);
        Form c(a);
        Form d;
        d = b;

        std::cout << a << std::endl;    
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        std::cout << d << std::endl;
    }  

    std::cout << std::endl;

    try {
        Form tmp("TooLow", 190, 190);
    }
    catch (Form::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form tmp("TooHigh", 0, 0);
    }
    catch (Form::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << std::endl;

    {
        try {
            Bureaucrat b("Bureaucrat", 1);
            Form f("Form", 100, 100);
            b.signForm(f);
        }
        catch (Form::GradeTooLowException& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << std::endl;
        try {
            Bureaucrat b("Bureaucrat", 150);
            Form f("Form", 1, 1);
            b.signForm(f);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}