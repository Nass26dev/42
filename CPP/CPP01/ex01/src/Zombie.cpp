#include "../include/Zombie.hpp"

Zombie::~Zombie() {
    std::cout << name << " is destroyed !" << std::endl;
}

void Zombie::announce(void) const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& newName) {
    name = newName;
}
