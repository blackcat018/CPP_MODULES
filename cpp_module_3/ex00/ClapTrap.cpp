#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : Name(name), hitPoints(10),energyPoints(10),attackDmg(0)
{
    std::cout << "clap trap " << this->Name << " has come to life!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) : Name(cpy.Name),hitPoints(cpy.hitPoints),energyPoints(cpy.energyPoints),attackDmg(cpy.attackDmg)
{
    std::cout << "clap trap " << this->Name << " was coppied from another one!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& op)
{
    if(this != &op)
    {
        this->Name = op.Name;
        this->attackDmg = op.attackDmg;
        this->energyPoints = op.energyPoints;
        this->hitPoints = op.hitPoints;
    }
    std::cout << "clap trap " << this->Name << " has been assigned!" << std::endl;
    return(*this);
}

ClapTrap::~ClapTrap(){}

void ClapTrap::attack(const std::string& target)
{
    if(hitPoints <= 0 || energyPoints <=0)
    {
        std::cout << "clap trap " << Name <<  " cannot attack at the moment! check if you have enough Energy or Enough Hit Points " << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "clap trap " << Name << " Attacks " << target << " causing it " << attackDmg<< " of damage!" <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints = hitPoints - amount;
    if(hitPoints < 0)
        hitPoints = 0;
    if(hitPoints == 0)
    {
        std::cout << "Clap Trap" << Name <<" has died! Rip" <<std::endl;
        return;
    }
    std::cout << "ClapTrap" << " has taked " << amount << " points of damage! please consider repairing asap!" <<std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(energyPoints <= 0)
    {
        std::cout << "You cannot repair Clap Trap " << Name << " because you have no energy!" << std::endl;
        return;
    }
    if(hitPoints <= 0)
    {
        std::cout << "you cannot heal a corps dude!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints = hitPoints + amount;
    std::cout << "clap trap " << Name << " has heald one point! the current healt is :" << hitPoints << std::endl; 
}