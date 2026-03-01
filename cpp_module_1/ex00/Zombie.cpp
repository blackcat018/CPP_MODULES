#include"Zombie.hpp"

Zombie::Zombie(std::string init) : name(init){}
Zombie::~Zombie()
{
    std::cout << name << " is no longer with us!" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

