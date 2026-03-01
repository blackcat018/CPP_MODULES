#include "harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. " << std::endl;
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;
}

typedef struct s_match
{
    std::string lv;
    void(Harl::*func)();
}t_match;

void Harl::complain(const std::string level)
{
    t_match karen[4] = {
        {"DEBUG",&Harl::debug},
        {"INFO",&Harl::info},
        {"WARNING",&Harl::warning},
        {"ERROR",&Harl::error}
    };
    int i = 0;
    while(i < 4)
    {
        if(karen[i].lv == level)
        {
            
            (this->*karen[i].func)();
            return;
        }
        i++;
    }
    std::cout << "Harl did not reach that level of entitlement... YET!" << std::endl;
    return;

}