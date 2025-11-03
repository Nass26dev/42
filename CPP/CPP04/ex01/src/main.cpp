#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int main() {
    const int N = 6;
    Animal* animals[N];

    for (int i = 0; i < N / 2; i++)
        animals[i] = new Dog();
    for (int i = N / 2; i < N; i++)
        animals[i] = new Cat();

    std::cout << "\n=== Test des sons ===" << std::endl;
    for (int i = 0; i < N; i++)
        animals[i]->makeSound();

    std::cout << "\n=== Test de la copie profonde ===" << std::endl;
    Dog basicDog;
    {
        Dog tmpDog = basicDog;
    }

    Cat basicCat;
    {
        Cat tmpCat(basicCat);
    }

    std::cout << "\n=== Suppression des animaux ===" << std::endl;
    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << "\n=== Fin du programme ===" << std::endl;
    return 0;
}