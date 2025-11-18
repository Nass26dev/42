#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& other);
        
        Serializer& operator=(const Serializer& other);

        ~Serializer();
    public:
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif