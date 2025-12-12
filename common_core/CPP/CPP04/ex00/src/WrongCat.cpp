#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "WrongCat : Default constructor was called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
    _type = other.getType();
    std::cout << "WrongCat : Copy constructor was called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        _type = other.getType();
    }
    std::cout << "WrongCat : Copy assignement constructor was called" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat : Destructor was called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Weird Meow 🐱" << std::endl;
}
