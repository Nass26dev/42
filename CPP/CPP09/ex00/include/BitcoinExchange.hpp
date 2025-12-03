#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
#include <string>
#include <exception>
#include <stdexcept>

class Date {
    private:
        const int _year;
        const int _month;
        const int _day;

        const int parseYear(const std::string& line, size_t len);
        const int parseMonth(const std::string& line, size_t len);
        const int parseDay(const std::string& line, size_t len);
    public:
        Date(const std::string& line, size_t len);
        Date(const Date& other);

        ~Date();

        const int getYear() const;
        const int getMonth() const;
        const int getDay() const;

        class FormatError : public std::exception {
            const char *what() const throw();  
        };
        class YearIsOutOfRange : public std::out_of_range {
            public:
                YearIsOutOfRange();
        };
        class MonthIsOutOfRange : public std::out_of_range {
            public:
                MonthIsOutOfRange();
        };
        class DayIsOutOfRange : public std::out_of_range {
            public:
                DayIsOutOfRange();
        };
};

typedef struct t_node {
    Date date;
    int value;

    t_node(Date d, int v)
        : date(d), value(v) {}
} node;

class BitcoinExchange {
    private:
        std::list<node> _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);

        BitcoinExchange& operator=(const BitcoinExchange& other);

        ~BitcoinExchange();

        void addElementToDatabase(const Date& date, const int value);
};

#endif
