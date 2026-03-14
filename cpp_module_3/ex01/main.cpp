#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n=== ClapTrap test ===\n" << std::endl;

    ClapTrap a("Alpha");

    a.attack("Target Dummy");
    a.takeDamage(3);
    a.beRepaired(2);

    std::cout << "\n=== ScavTrap creation ===\n" << std::endl;

    ScavTrap s("Guardian");

    std::cout << "\n=== ScavTrap actions ===\n" << std::endl;

    s.attack("Bandit");
    s.takeDamage(20);
    s.beRepaired(10);

    std::cout << "\n=== Guard Gate ability ===\n" << std::endl;

    s.guardGate();

    std::cout << "\n=== Energy depletion test ===\n" << std::endl;

    for (int i = 0; i < 55; i++)
        s.attack("Training Bot");

    std::cout << "\n=== Death test ===\n" << std::endl;

    s.takeDamage(200);
    s.attack("Ghost");
    s.beRepaired(10);

    std::cout << "\n=== Program ending ===\n" << std::endl;

    return 0;
}

