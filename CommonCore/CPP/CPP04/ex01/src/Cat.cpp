#include "../include/Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    _brain = new Brain();
    std::cout << "Cat : Default constructor was called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal() {
    _type = other.getType();
    _brain = new Brain(*other._brain);
    std::cout << "Cat : Copy constructor was called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        _type = other.getType();
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << "Cat : Copy assignement constructor was called" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat : Destructor was called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow 🐱" << std::endl;
}

Brain *Cat::getBrain() const {
    return _brain;
}