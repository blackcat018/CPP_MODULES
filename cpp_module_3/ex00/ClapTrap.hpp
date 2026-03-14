#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string Name;
        int hitPoints;
        int energyPoints;
        int attackDmg;
    public:
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& cpy);
        ClapTrap& operator=(const ClapTrap& op);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif