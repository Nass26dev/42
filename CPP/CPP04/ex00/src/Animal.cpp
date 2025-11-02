#include "../include/Animal.hpp"

Animal::Animal() {}

Animal::~Animal() {}

std::string Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "Animal noise..." << std::endl;
}