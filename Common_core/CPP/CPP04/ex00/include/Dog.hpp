#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& Animal);

        ~Dog();
        
        void makeSound() const;
};

#endif
