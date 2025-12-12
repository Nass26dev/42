#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("") {
    std::cout << "AAnimal : Default constructor was called" << std::endl;
}

AAnimal::AAnimal(const std::string& type) {
    _type = type;
    std::cout << "AAnimal : Constructor was called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    _type = other.getType();
    std::cout << "AAnimal : Copy constructor was called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal : Copy assignement constructor was called" << std::endl;
    if (this != &other) {
        _type = other.getType();
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal : Destructor was called" << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "..." << std::endl;
}

std::string AAnimal::getType() const {
    return _type;
}
