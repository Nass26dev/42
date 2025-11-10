#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat Josianne("Josianne", 151);
        std::cout << Josianne << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "catch : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat Jacquie("Jaquie", 0);
        std::cout << Jacquie << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "catch : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat Bob("Bob", 150);
        std::cout << Bob << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << "catch : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat Bob2("Bob2", 1);
        std::cout << Bob2 << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "catch : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat Bob3("Bob3", 1);
        std::cout << Bob3 << std::endl;
        Bob3.decrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "catch : " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat Bob4("Bob4", 150);
        std::cout << Bob4 << std::endl;
        Bob4.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << "catch : " << e.what() << std::endl;
    }

    return 0;
}