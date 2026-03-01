#include "HumanA.hpp"

HumanA::HumanA(const std::string& alias,Weapon& tank) : name(alias), arm(tank){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << arm.getType() << std::endl;
}
Weapon& HumanA::getWeapon()
{
    return(arm);
}