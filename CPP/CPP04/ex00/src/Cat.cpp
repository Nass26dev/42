#include "../include/Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow 🐱" << std::endl;
}
