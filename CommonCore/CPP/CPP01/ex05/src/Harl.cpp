#include "../include/Harl.hpp"

void Harl::debug(void) {
    
    std::cout << DEBUG_MESSAGE << std::endl;
}

void Harl::info(void) {
    std::cout << INFO_MESSAGE << std::endl;
}

void Harl::warning(void) {
    std::cout << WARNING_MESSAGE << std::endl;
}

void Harl::error(void) {
    std::cout << ERROR_MESSAGE << std::endl;
}

void Harl::complain(std::string level) {
    std::map<std::string, void(Harl::*)()> table;

    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
        std::cout << "wrong level !" << std::endl;
        return ;
    }
    table["DEBUG"] = &Harl::debug;
    table["INFO"] = &Harl::info;
    table["WARNING"] = &Harl::warning;
    table["ERROR"] = &Harl::error;
    
    (this->*table[level])();
}
