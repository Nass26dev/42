#include "../include/Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "wrong numbers of arguments" << std::endl;
        return (1);
    }
    std::string str(argv[1]);
    Harl harl;
    harl.complain(str);
    return (0);
}
