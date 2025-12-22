#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>

class NoOccurenceFound : public std::exception {
    public:
        virtual const char *what() const throw() {return "Number not found";};
};

template <typename T>
    typename T::iterator easyfind(T& container, int to_find);

#endif

#include "../src/easyfind.tpp"
