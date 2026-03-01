#include"Zombie.hpp"

Zombie *Zombie::newZombie(std::string n_name)
{
    Zombie *newGuy = new Zombie(n_name) ;
    return(newGuy);
}
