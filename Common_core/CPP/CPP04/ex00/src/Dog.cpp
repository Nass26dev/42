#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog : Default constructor was called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal() {
    _type = other.getType();
    std::cout << "Dog : Copy constructor was called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Dog : Copy assignement constructor was called" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog : Destructor was called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof 🐶" << std::endl;
}
