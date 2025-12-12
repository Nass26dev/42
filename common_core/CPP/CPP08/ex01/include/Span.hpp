#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

class Span {
    private:
        int *_array;
        int _size;
        int _fill_index;

        int min() const;
        int max() const;
        int *sortArray(int *array);
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        ~Span();

        Span& operator=(const Span& other);
        void addNumber(int nb);
        void addMultipleNumbers(int nb);
        void shortestSpan() const;
        void longestSpan() const;

    class IndexIsOutOfRange : public std::exception {
        public:
            virtual const char *what() const throw();
    };

    class NoSpanFounded : public std::exception {
        public:
            virtual const char *what() const throw();
    };
};

#endif
