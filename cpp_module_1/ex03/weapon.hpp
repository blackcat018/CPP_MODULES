#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon(const std::string& initial);
        std::string getType() const;
        void setType(std::string passed);
};

#endif