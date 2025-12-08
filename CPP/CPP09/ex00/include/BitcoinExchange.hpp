#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <list>
#include <string>

class Error {
    public:
        class FileOpening : std::exception {
            public:
                const char *what() const throw();
        };
        class HeaderFormat : std::exception {
            public:
                const char *what() const throw();
        };
};

class Date {
    private:
        int _year;
        int _month;
        int _day;
    public:
        Date();
        Date(int year, int month, int day);
        Date(const Date& other);
        Date& operator=(const Date& other);
        bool operator<=(const Date& other) const;
        ~Date();

        void setYear(int year);
        void setMonth(int month);
        void setDay(int day);
        int getYear() const;
        int getMonth() const;
        int getDay() const;
};

typedef struct t_node {
    Date date;
    double value;

    t_node(Date d, double v)
        : date(d), value(v) {}
}   node;

class BitcoinExchange {
    private:
        std::list<node> _database;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void loadDatabase();
        void addElementToDatabase(Date date, double value);
        Date extractDate(std::string& line);
        double extractValue(std::string& line);
        void printDatabase() const;
        std::list<node>& getDatabase();
};

#endif
