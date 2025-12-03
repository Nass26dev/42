#include "BitcoinExchange.hpp"

/* Exception */

const char *Date::FormatError::what() const throw() {return "Format error, correct format : 'Year-Month-Day | value'";}
Date::YearIsOutOfRange::YearIsOutOfRange() : std::out_of_range("Year is out of range") {}
Date::MonthIsOutOfRange::MonthIsOutOfRange() : std::out_of_range("Month is out of range") {}
Date::DayIsOutOfRange::DayIsOutOfRange() : std::out_of_range("Day is out of range") {}

/* Date class */

Date::Date(const std::string& line, size_t len)
    : _year(parseYear(line, len)),
    _month(parseMonth(line, len)),
    _day(parseDay(line, len)) {

    if (_year < 2009 || _year > 2025) {
        throw YearIsOutOfRange();
    }
    else if (_month < 1 || _month > 12) {
        throw MonthIsOutOfRange();
    }
    else if (_day < 1 || _day > 31) {
        throw DayIsOutOfRange();
    }
}

const int Date::parseYear(const std::string& line, size_t len) {
    size_t i = 0;
    int year = 0;

    while (i < len && isdigit(line[i])) {
        year = year * 10 + (line[i] - '0');
        i++;
    }
    if (i >= len || line[i] != '-')
        throw FormatError();
    return year;
}

const int Date::parseMonth(const std::string& line, size_t len) {
    size_t i = 0;

    while (i < len && line[i] != '-') i++;
    if (++i >= len || !isdigit(line[i])) throw FormatError();

    int month = 0;
    while (i < len && isdigit(line[i])) {
        month = month * 10 + (line[i] - '0');
        i++;
    }
    if (i >= len || line[i] != '-') throw FormatError();
    return month;
}

const int Date::parseDay(const std::string& line, size_t len) {
    size_t i = 0;

    while (i < len && line[i] != '-') i++;
    if (++i >= len) throw FormatError();

    while (i < len && line[i] != '-') i++;
    if (++i >= len || !isdigit(line[i])) throw FormatError();

    int day = 0;
    while (i < len && isdigit(line[i])) {
        day = day * 10 + (line[i] - '0');
        i++;
    }
    return day;
}
Date::Date(const Date& other) : _year(other._year), _month(other._month), _day(other._day) {}

const int Date::getYear() const {
    return _year;
}

const int Date::getMonth() const {
    return _month;
}

const int Date::getDay() const {
    return _day;
}

Date::~Date() {}

/* BitcoinExchange class */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::addElementToDatabase(const Date& date, const int value) {
    this->_database.emplace_back(date, value);
}