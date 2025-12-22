#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
    private:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);

        ~Brain();

        void setIdea(const std::string& idea, const int index);
        std::string getIdea(const int index) const;

        class IndexIsTooLow : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class IndexIsTooHigh : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};

#endif