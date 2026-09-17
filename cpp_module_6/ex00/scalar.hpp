#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter operator=(const ScalarConverter &op);
        ~ScalarConverter();
    public:
        static void convert(const std::string &str);
};

#endif