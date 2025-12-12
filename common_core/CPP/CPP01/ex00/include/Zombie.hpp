#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(const std::string& name);
    ~Zombie();
    void announce(void) const;
};

// randomChump.cpp
void randomChump(std::string name);

// newZombie.cpp
Zombie* newZombie(std::string name);

#endif
