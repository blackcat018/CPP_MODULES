#include"Zombie.hpp"

void Zombie::randomChump( std::string c_name )
{
    Zombie chump(c_name);
    chump.announce();
}
