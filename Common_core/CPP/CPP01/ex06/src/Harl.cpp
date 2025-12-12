#include "../include/Harl.hpp"

void Harl::debug(void) {
    std::cout << "[ DEBUG ]" << std::endl << DEBUG_MESSAGE << std::endl;
}

void Harl::info(void) {
    std::cout << "[ INFO ]" << std::endl << INFO_MESSAGE << std::endl;
}

void Harl::warning(void) {
    std::cout << "[ WARNING ]" << std::endl << WARNING_MESSAGE << std::endl;
}

void Harl::error(void) {
    std::cout << "[ ERROR ]" << std::endl << ERROR_MESSAGE << std::endl;
}

int getLevelIndex(const std::string& level) {
    if (level == "DEBUG")
        return (0);
    else if (level == "INFO")
        return (1);
    else if (level == "WARNING")
        return (2);
    else if (level == "ERROR")
        return (3);
    return (4);
}

void Harl::complain(std::string level) {
    std::map<std::string, void(Harl::*)()> table;
    int index;

    table["DEBUG"] = &Harl::debug;
    table["INFO"] = &Harl::info;
    table["WARNING"] = &Harl::warning;
    table["ERROR"] = &Harl::error;
    index = getLevelIndex(level);
    
    switch (index)
    {
    case 0:
        (this->*table["DEBUG"])();
        // fall through
    case 1:
        (this->*table["INFO"])();
        // fall through
    case 2:
        (this->*table["WARNING"])();
        // fall through
    case 3:
        (this->*table["ERROR"])();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}
