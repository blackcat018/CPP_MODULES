#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie(std::string init);
        ~Zombie();
        void announce();
        Zombie* newZombie( std::string n_name );
        void randomChump( std::string c_name );
};

#endif