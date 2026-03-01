#include "harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]\n" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<std::endl;
}

void Harl::info()
{
    std::cout << "\n[INFO]\n" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
     std::cout << "\n[WARNING]\n" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
     std::cout << "\n[ERROR]\n" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;
}

void Harl::complain(const std::string level)
{
    std::string match[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while(i < 4 && match[i] != level)
        i++;
    switch (i)
    {
    case 0:
        debug();
        // fall through
    case 1:
        info();
        // fall through
    case 2:
        warning();
        // fall through
    case 3:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}