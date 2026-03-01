#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string smia)
{
    int i = 0;
    Zombie *hoard = new Zombie[N];
    while(i < N)
    {
        hoard[i].assigne_name(smia);
        i++;
    }
    return(hoard);
}