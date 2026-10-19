#include "Pmergeme.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cout << "Please enter an input!" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe test;
        test.sortAndTime(ac,av);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;  
    }
}