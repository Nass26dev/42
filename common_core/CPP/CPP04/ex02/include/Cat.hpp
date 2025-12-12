#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& Animal);

        ~Cat();

        void makeSound() const;
        Brain *getBrain() const;
};

#endif
