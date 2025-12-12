#include "../include/Animal.hpp"

Animal::Animal() : _type("") {
    std::cout << "Animal : Default constructor was called" << std::endl;
}

Animal::Animal(const std::string& type) {
    _type = type;
    std::cout << "Animal : Constructor was called" << std::endl;
}

Animal::Animal(const Animal& other) {
    _type = other.getType();
    std::cout << "Animal : Copy constructor was called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal : Copy assignement constructor was called" << std::endl;
    if (this != &other) {
        _type = other.getType();
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal : Destructor was called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "..." << std::endl;
}

std::string Animal::getType() const {
    return _type;
}
