#ifndef DIAMONDTRAP
#define DIAMONDTRAP

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(const std::string& smia);
        DiamondTrap(const DiamondTrap& cpy);
        DiamondTrap& operator=(const DiamondTrap& op);
        ~DiamondTrap();
        void attack(const std::string& target);
        void whoAmI();
};

#endif