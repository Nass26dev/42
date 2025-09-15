#include "../include/Zombie.hpp"

int main() {
    randomChump("Stack");
    Zombie* z1 = newZombie("Heap");
    z1->announce();

    delete (z1);
    return (0);
}
