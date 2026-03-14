#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n=== DiamondTrap Creation ===\n" << std::endl;

    DiamondTrap d("Diamond");

    std::cout << "\n=== Attack Test (should use ScavTrap attack) ===\n" << std::endl;

    d.attack("Bandit");

    std::cout << "\n=== Damage Test ===\n" << std::endl;

    d.takeDamage(30);

    std::cout << "\n=== Repair Test ===\n" << std::endl;

    d.beRepaired(20);

    std::cout << "\n=== WhoAmI Test ===\n" << std::endl;

    d.whoAmI();

    std::cout << "\n=== Energy Exhaustion Test ===\n" << std::endl;

    for (int i = 0; i < 60; i++)
        d.attack("Training Dummy");

    std::cout << "\n=== Death Test ===\n" << std::endl;

    d.takeDamage(200);
    d.attack("Ghost");
    d.beRepaired(10);

    std::cout << "\n=== Copy Constructor Test ===\n" << std::endl;

    DiamondTrap copy(d);

    copy.whoAmI();

    std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;

    DiamondTrap other("Other");
    other = d;

    other.whoAmI();

    std::cout << "\n=== Program Ending ===\n" << std::endl;

    return 0;
}
