#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"


class FragTrap:public ClapTrap
{
    public:
        FragTrap(const std::string &smia);
        FragTrap(const FragTrap& cpy);
        FragTrap& operator=(const FragTrap& op);
        ~FragTrap();
        void highFivesGuys(void);
        void attack(const std::string& target);
};

#endif