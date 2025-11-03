#include "../include/Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    _brain = new Brain;
    std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof 🐶" << std::endl;
}

Dog::Dog(const Dog& other) {
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}