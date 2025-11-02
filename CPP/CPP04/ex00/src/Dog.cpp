#include "../include/Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof 🐶" << std::endl;
}