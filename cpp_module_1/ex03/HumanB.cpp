#include "HumanB.hpp"

HumanB::HumanB(const std::string& noun) : name(noun), weep(NULL) {}

void HumanB::attack()
{
    if(!weep)
         std::cout << name << " has no weapon!" << std::endl;
    else
        std::cout << name << " attacks with their " << weep->getType() << std::endl;
}
void HumanB::setWeapon(Weapon& wep)
{
    weep = &wep;
}