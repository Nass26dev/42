#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    virtual ~Cat();
    void makeSound() const;
};

#endif