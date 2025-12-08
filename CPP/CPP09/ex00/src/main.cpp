#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>
#include <cstdlib>

bool lineIsCorrectlyFormated(const std::string& line) {
    size_t i = 0;
    int dotCount = 0;

    // year
    for (int j = 0; j < 4; j++, i++)
        if (i >= line.size() || !std::isdigit(line[i])) return false;

    if (i >= line.size() || line[i++] != '-') return false;

    // month
    for (int j = 0; j < 2; j++, i++)
        if (i >= line.size() || !std::isdigit(line[i])) return false;

    if (i >= line.size() || line[i++] != '-') return false;

    // day
    for (int j = 0; j < 2; j++, i++)
        if (i >= line.size() || !std::isdigit(line[i])) return false;

    // " | "
    if (i >= line.size() || line[i++] != ' ') return false;
    if (i >= line.size() || line[i++] != '|') return false;
    if (i >= line.size() || line[i++] != ' ') return false;

    // value
    if (line[i] == '-')
        i++;
    if (i >= line.size() || !std::isdigit(line[i])) return false;

    while (i < line.size() && (std::isdigit(line[i]) || line[i] == '.')) {
        if (line[i] == '.') {
            if (dotCount++ > 0) return false;
        }
        i++;
    }
    return (i == line.size());
}


Date parseDate(std::string& line) {
    Date date;
    int year = 0, month = 0, day = 0;
    size_t len = line.length(), i = 0;

    while (i < len && std::isdigit(line[i])) {
        year = year * 10 + (line[i] - '0');
        i++;
    }
    i++;
    while (i < len && std::isdigit(line[i])) {
        month = month * 10 + (line[i] - '0');
        i++;
    }
    i++;
    while (i < len && isdigit(line[i])) {
        day = day * 10 + (line[i] - '0');
        i++;
    }
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
    return date;
}

double parseValue(std::string& line) {
    int i = 0;
    while (line[i] != '|') {
        i++;
    }
    i += 2;
    const char *p = line.c_str() + i;
    char *endPtr;
    double value = std::strtod(p, &endPtr);
    (void)endPtr;
    return value;
}

bool manageError(Date &date, double value) {
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return true;
    }
    else if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return true;
    }
    else if (date.getYear() > 2025) {
        std::cout << "Error: year can't be > 2025" << std::endl;
        return true;
    }
    else if (date.getYear() < 2009
            || (date.getYear() == 2009 && date.getMonth() == 1 && date.getDay() < 2)) {
        std::cout << "Error: oldest date possible is 2009-01-02" << std::endl;
        return true;
    }
    else if (date.getMonth() < 1 || date.getMonth() > 12) {
        std::cout << "Error: month must be beetween 01 and 12" << std::endl;
        return true;
    }
    else if (date.getDay() < 1 || date.getDay() > 31) {
        std::cout << "Error: day must be beetween 01 and 31" << std::endl;
        return true;
    }
    return false;
}

void convert(Date date, double value, BitcoinExchange& db) {
    const std::list<node>& btcHistory = db.getDatabase();
    double rate = -1.0;
    
    for (std::list<node>::const_iterator it = btcHistory.begin(); it != btcHistory.end(); ++it) {
        if (it->date <= date) {
            rate = it->value;
        }
        else {
            break;
        }
    }
    if (rate < 0) {
        std::cout << "Error: no BTC rate available for " 
              << date.getYear() << "-" 
              << (date.getMonth() < 10 ? "0" : "") << date.getMonth() << "-" 
              << (date.getDay() < 10 ? "0" : "") << date.getDay() 
              << std::endl;
        return;
    }
    double result = value * rate;
    std::cout << date.getYear() << "-"
              << (date.getMonth() < 10 ? "0" : "") << date.getMonth() << "-"
              << (date.getDay() < 10 ? "0" : "") << date.getDay()
              << " => " << value << " = "
              << std::fixed << std::setprecision(2)
              << result
              << std::endl;
}

void manageInput(char *filename, BitcoinExchange& db) {
    std::ifstream infile(filename);
    std::string line;
    if (!infile) {
        throw Error::FileOpening();
    }
    getline(infile, line);
    if (line != "date | value") {
        throw Error::HeaderFormat();
    }
    while (getline(infile, line)) {
        if (!lineIsCorrectlyFormated(line)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        Date date = parseDate(line);
        double value = parseValue(line);
        if (manageError(date, value)) {
            continue;
        }
        convert(date, value, db);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange db;
        db.loadDatabase();
        manageInput(argv[1], db);
    }
    catch (Error::FileOpening& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
