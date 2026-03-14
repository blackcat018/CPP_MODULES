#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== ClapTrap Test ===\n" << std::endl;

    ClapTrap clap("CL4P");

    clap.attack("Bandit");
    clap.takeDamage(4);
    clap.beRepaired(2);

    std::cout << "\n=== ScavTrap Test ===\n" << std::endl;

    ScavTrap scav("SC4V");

    scav.attack("Bandit");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n=== FragTrap Test ===\n" << std::endl;

    FragTrap frag("FR4G");

    frag.attack("Bandit");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n=== Energy Exhaustion Test ===\n" << std::endl;

    for (int i = 0; i < 105; i++)
        frag.attack("Training Dummy");

    std::cout << "\n=== Death Test ===\n" << std::endl;

    frag.takeDamage(200);
    frag.attack("Ghost");
    frag.beRepaired(10);

    std::cout << "\n=== Program Ending ===\n" << std::endl;

    return 0;
}

