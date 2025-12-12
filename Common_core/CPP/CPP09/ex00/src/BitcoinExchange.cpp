#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <iostream>

/* Error */

const char *Error::FileOpening::what() const throw() {
    return "Error: could not open file.";
}
const char *Error::HeaderFormat::what() const throw() {
    return "Error: File must start with 'date | value'.";
}

/* Date */

Date::Date() : _year(0), _month(0), _day(0) {}

Date::Date(int year, int month, int day)
    : _year(year), _month(month), _day(day) {}

Date::Date(const Date& other) {
    _year = other._year;
    _month = other._month;
    _day = other._day;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        _year = other._year;
        _month = other._month;
        _day = other._day;
    }
    return *this;
}

bool Date::operator<=(const Date& other) const {
    if (_year != other._year)
       return _year < other._year;
    if (_month != other._month)
        return _month < other._month;
    return _day <= other._day;
}

void Date::setYear(int year) {
    _year = year;
}

void Date::setMonth(int month) {
    _month = month;
}

void Date::setDay(int day) {
    _day = day;
}

int Date::getYear() const {
    return _year;
}

int Date::getMonth() const {
    return _month;
}

int Date::getDay() const {
    return _day;
}

Date::~Date() {}

/* BitcoinExchange */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase() {
    std::ifstream infile("data.csv");
    std::string line;

    if (!infile)
        throw Error::FileOpening();

    getline(infile, line);
    while (getline(infile, line)) {
        Date date = extractDate(line);
        double value = extractValue(line);
        this->addElementToDatabase(date, value);
    }
    
}

void BitcoinExchange::addElementToDatabase(Date date, double value) {
    this->_database.push_back(node(date, value));
}

Date BitcoinExchange::extractDate(std::string& line) {
    Date date;
    int i = 0, year = 0, month = 0, day = 0;

    while (std::isdigit(line[i])) {
        year = year * 10 + (line[i] - '0');
        i++;    
    }
    i++;
    while (std::isdigit(line[i])) {
        month = month * 10 + (line[i] - '0');
        i++;
    }
    i++;
    while (std::isdigit(line[i])) {
        day = day * 10 + (line[i] - '0');
        i++;
    }
    date.setYear(year);
    date.setMonth(month);
    date.setDay(day);
    return date;
}

double BitcoinExchange::extractValue(std::string& line) {
    double value = 0;
    int i = 0;

    while (line[i] != ',')
        i++;
    i++;
    const char *p = line.c_str() + i;
    char *endPtr;

    value = std::strtod(p, &endPtr);
    (void)endPtr;
    return value;
}

std::list<node>& BitcoinExchange::getDatabase() {
    return _database;
}
