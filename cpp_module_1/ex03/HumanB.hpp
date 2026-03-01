#ifndef HUMANB_HPP
#define HUMANB_HPP

#include"weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weep;
    public:
        HumanB(const std::string& noun);
        void attack();
        void setWeapon(Weapon& wep);
};
#endif