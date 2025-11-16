#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static void manageChar(const std::string &input);
        static void manageInt(const std::string &input);
        static void manageFloat(const std::string &input);
        static void manageDouble(const std::string &input);
    public:
        static void convert(const std::string& input);     
};

#endif
