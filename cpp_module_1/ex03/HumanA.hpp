#ifndef HUMANA_HPP
#define HUMANA_HPP

#include"weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& arm;
    public:
        HumanA(const std::string& alias, Weapon& tank);
        Weapon& getWeapon();
        void attack();
};

#endif