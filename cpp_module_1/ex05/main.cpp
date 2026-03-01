#include "harl.hpp"

int main(int ac, char **av)
{
    if(ac !=2)
    {
        std::cout << "wrong number of arguments!" <<std::endl;
        return(1);
    }
    Harl Karen;

    Karen.complain(av[1]);
    return(0);
}