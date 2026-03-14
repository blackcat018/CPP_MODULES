#include"ScavTrap.hpp"
#include"ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string& nom) : ClapTrap(nom)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDmg = 20;
    std::cout << "this is the scav trap default constructor!" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap&cpy) : ClapTrap(cpy)
{
    std::cout << "this is the scavTrap copying constructor!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& op)
{
    ClapTrap::operator=(op);
    std::cout << "this is the operator assignement Constructor" << std::endl;
    return(*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "DIYING! DYING! GOODBYE CRUEL WORLD! ... bleh X(" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(hitPoints <= 0 || energyPoints <=0)
    {
        std::cout << "ScavTrap " << Name <<  " cannot attack at the moment!\n" <<"check if you have enough Energy or Enough Hit Points" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "ScavTrap " << Name << " Attacks " << target << " causing it " << attackDmg<< " damage!" <<std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << " the ScaveTrap named : " << Name << "is now in GUARD MODE!" <<std::endl;
}