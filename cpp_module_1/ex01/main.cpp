#include"Zombie.hpp"

int main()
{
    Zombie *Hoard = zombieHorde(8,"bruh");

    int i = 0;
    while(i < 8)
    {
        Hoard[i].announce();
        i++;
    }
    delete[]Hoard;
    return(0);
}