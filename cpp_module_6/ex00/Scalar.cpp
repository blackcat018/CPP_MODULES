#include "scalar.hpp"

#include "scalar.hpp"

static bool isPseudo(const std::string &str)
{
    return (str == "nan"  || str == "nanf"  || 
            str == "-inf" || str == "-inff" || 
            str == "+inf" || str == "+inff" || 
            str == "inf"  || str == "inff");
}

static void handlePseudo(const std::string &str)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str == "nan" || str == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "-inf" || str == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

static void printAll(double val)
{
    if (val < 0 || val > 127 || std::isnan(val))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(val)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    if (val < INT_MIN || val > INT_MAX || std::isnan(val))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
    if (isPseudo(str))
    {
        handlePseudo(str);
        return;
    }

    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        char c = str[0];
        printAll(static_cast<double>(c));
        return;
    }

    char *endptr;
    double val = std::strtod(str.c_str(), &endptr);

    if (*endptr != '\0' && std::string(endptr) != "f")
    {
        std::cout << "Error: Invalid literal format" << std::endl;
        return;
    }
    printAll(val);
}