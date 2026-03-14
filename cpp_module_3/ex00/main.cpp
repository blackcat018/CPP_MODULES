#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << "\n=== Basic attacks ===" << std::endl;
    a.attack("Bravo");
    b.takeDamage(5);

    std::cout << "\n=== Repair ===" << std::endl;
    b.beRepaired(3);

    std::cout << "\n=== Multiple attacks ===" << std::endl;
    for (int i = 0; i < 12; i++)
    {
        a.attack("Training Dummy");
    }

    std::cout << "\n=== Heavy damage ===" << std::endl;
    b.takeDamage(20);

    std::cout << "\n=== Try actions with 0 HP ===" << std::endl;
    b.attack("Alpha");
    b.beRepaired(5);

    std::cout << "\n=== Energy exhaustion test ===" << std::endl;
    ClapTrap c("Charlie");

    for (int i = 0; i < 11; i++)
    {
        c.beRepaired(1);
    }

    std::cout << "\n=== Program ending ===" << std::endl;
    return 0;
}
