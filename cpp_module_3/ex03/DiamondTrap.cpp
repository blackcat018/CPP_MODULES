#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& smia) : ClapTrap(smia +"_clap_name"),ScavTrap(smia),FragTrap(smia)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDmg = 30;
    _name = smia;
    std::cout << "Shine bright like the DiamondTrap named : "<< this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& cpy) : ClapTrap(cpy),ScavTrap(cpy),FragTrap(cpy)
{
    _name = cpy._name;
    std::cout << "DiamondTrap " << this->_name << "has copied another because he is insecure!" <<std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap&op)
{
    if(this != &op)
    {
        ClapTrap::operator=(op);
        _name = op._name;
    }
    std::cout << "copy assignement operator has re evaluated the DiamondTrap " << this->_name << std::endl;
    return(*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "the diamond" << this->_name <<" is shattered! what a sad day!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);//specified by the subject!
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << _name
              << ": Who am I? I am " << _name
              << " and my ClapTrap name is " << ClapTrap::Name << "!" << std::endl;
}
