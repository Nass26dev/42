#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static void manageChar(const std::string& input);
        static void manageInt(const std::string& input);
        static void manageFloat(const std::string& input);
        static void manageDouble(const std::string& input);
        static void manageSpecialCase(const std::string& input);
        static bool isSpecialCase(const std::string& input);
        static bool isChar(size_t len);
        static bool isInt(const std::string& input, size_t len);
        static bool isFloat(const std::string& input, size_t len);
        static bool isDouble(const std::string& input, size_t len);
    public:
        static void convert(const std::string& input);     
};

#endif
