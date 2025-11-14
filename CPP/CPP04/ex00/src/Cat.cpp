#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << "Cat : Default constructor was called" << std::endl;
}

Cat::Cat(const Cat& other) {
    _type = other.getType();
    std::cout << "Cat : Copy constructor was called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "Cat : Copy assignement constructor was called" << std::endl;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat : Destructor was called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow 🐱" << std::endl;
}
