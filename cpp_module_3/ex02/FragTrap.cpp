#include"FragTrap.hpp"
#include"ClapTrap.hpp"


FragTrap::FragTrap(const std::string& smia) : ClapTrap(smia)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDmg = 30;
    std::cout << "YO! THIS IS THE FRAGTRAP DEFAULT CONSTRUCTOR! SHOW SOME RESPECT!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy)
{
    std::cout << "the copying instructor just entered the room!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& op)
{
    ClapTrap::operator=(op);
    std::cout << "Assignement Constructor just did its thing!" << std::endl;
    return(*this);
}

FragTrap::~FragTrap()
{
    std::cout << "All good things must some to an end, Never thought it would be my time!" << std::endl;
}
void FragTrap::attack(const std::string& target)
{
    if(hitPoints <= 0 || energyPoints <=0)
    {
        std::cout << "FragTrap " << Name <<  " Has Failed in its Attack\n" <<"it does not have enough Energy or Enough Hit Points" << std::endl;
        return;
    }
    energyPoints--;
    std::cout << "FragTrap " << Name << " Attacked " << target << " causing it " << attackDmg<< " damage!" <<std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap" << Name << "celebrates with you with a High Five!🙌" << std::endl;
}