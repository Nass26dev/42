#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("") {
    std::cout << "WrongAnimal : Default constructor was called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) {
    _type = type;
    std::cout << "WrongAnimal : Constructor was called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    _type = other.getType();
    std::cout << "WrongAnimal : Copy constructor was called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal : Copy assignement constructor was called" << std::endl;
    if (this != &other) {
        _type = other.getType();
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal : Destructor was called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "(Weird) ..." << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}
