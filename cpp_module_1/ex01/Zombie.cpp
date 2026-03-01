#include"Zombie.hpp"

Zombie::Zombie(){}
Zombie::Zombie(std::string init) : name(init){}
Zombie::~Zombie()
{
    std::cout << name << " is no longer with us!" << std::endl;
}

void Zombie::assigne_name(std::string smia)
{
    name = smia;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

