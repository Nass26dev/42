#include "../include/Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow 🐱" << std::endl;
}

Cat::Cat(const Cat& other) {
    _type = other._type;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other._type;
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}