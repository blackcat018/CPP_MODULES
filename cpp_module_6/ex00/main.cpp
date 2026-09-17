#include "scalar.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "no!" << std::endl;
    }
    ScalarConverter::convert(av[1]);
}