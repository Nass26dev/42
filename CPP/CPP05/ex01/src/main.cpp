#include "../include/Bureaucrat.hpp"

int main() {
    try
    {
        Form contract("test", 151, 20);
        std::cout << contract << std::endl;
    }
    catch(const std::exception& e)
    {
         std::cerr << "catch : " << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Form contract("test", 0, 20);
        std::cout << contract << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch : " << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Form contract("test", 80, 151);
        std::cout << contract << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch : " << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Form contract("test", 80, 0);
        std::cout << contract << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch : " << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b("Bob", 1);
        Form c("test", 20, 20);
        std::cout << c << std::endl;
        b.signForm(c);
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch : " << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        Bureaucrat b("Bob", 150);
        Form c("test", 20, 20);
        std::cout << c << std::endl;
        b.signForm(c);
    }
    catch(const std::exception& e)
    {
        std::cerr << "catch : " << e.what() << '\n';
    }

    return 0;
}