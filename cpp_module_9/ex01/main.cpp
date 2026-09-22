#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error! Your input is invalid!" <<std::endl;
        return 1;
    }
    try
    {
        Rpn calc;
        int res = calc.doOp(av[1]);
        std::cout << "the result is : "<< res << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}