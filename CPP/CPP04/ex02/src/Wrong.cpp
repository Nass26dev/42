#include "../include/Wrong.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some generic wrong animal sound..." << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}


WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong meow" << std::endl;
}
