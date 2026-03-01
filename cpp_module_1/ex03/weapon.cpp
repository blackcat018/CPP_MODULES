#include "weapon.hpp"

Weapon::Weapon(const std::string& initial) : type(initial){}

std::string Weapon::getType() const
{
    return(type);
}

void Weapon::setType(std::string passed)
{
    type = passed;
}
