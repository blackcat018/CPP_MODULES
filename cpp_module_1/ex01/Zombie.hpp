#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string init);
        void assigne_name(std::string smia);
        ~Zombie();
        void announce();
        Zombie* newZombie( std::string n_name );
        void randomChump( std::string c_name );
};

Zombie* zombieHorde( int N, std::string smia);

#endif