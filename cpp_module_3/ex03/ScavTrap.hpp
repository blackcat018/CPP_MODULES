#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    //we do not need a private section for the vars as it INHERITS the vars from the claptrap
    public:
        ScavTrap(const std::string& nom);
        ScavTrap(const ScavTrap& cpy);
        ScavTrap& operator=(const ScavTrap& op);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif