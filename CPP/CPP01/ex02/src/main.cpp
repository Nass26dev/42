#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "Address of string variable : " << &str << std::endl;
    std::cout << "Address held by stringPTR  : " << stringPTR << std::endl;
    std::cout << "Address held by stringREF  : " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Value of string variable   : " << str << std::endl;
    std::cout << "Value pointed by stringPTR : " << *stringPTR << std::endl;
    std::cout << "Value pointed by stringREF : " << stringREF << std::endl;

    return (0);
}
