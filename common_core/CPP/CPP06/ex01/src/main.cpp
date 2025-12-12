#include "Serializer.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./Serialize <username>" << std::endl;
        return 1;
    }
    Data d;
    d.username = argv[1];
    uintptr_t ptr = Serializer::serialize(&d);
    Data *unserialized = Serializer::deserialize(ptr);
    std::cout << "result: " << unserialized->username << std::endl;
    return 0;
}
