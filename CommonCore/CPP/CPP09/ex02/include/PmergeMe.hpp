#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        bool isPositive(const std::string& str) const;

        void mergeInsertVector(std::vector<int>& vec);
        void vectorRecursive(std::vector<int>& vec, size_t left, size_t right);
        void insertVector(std::vector<int>& vec, int value);

        void mergeInsertDeque(std::deque<int>& deq);
        void dequeRecursive(std::deque<int>& deq, size_t left, size_t right);
        void insertDeque(std::deque<int>& deq, int value);
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseArgs(int argc, char **argv);
        void sortAndDisplay();
        class NoArgs : public std::exception {
            public:
                const char *what() const throw();
        };
        class IntNegative : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif
