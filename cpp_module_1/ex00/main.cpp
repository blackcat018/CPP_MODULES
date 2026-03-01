#include"Zombie.hpp"

int main()
{
    //normal zombie object declaration
    Zombie test("omar");
    test.announce();
    //newZombie declaration
    Zombie *jadid = test.newZombie("newDude");
    jadid->announce();
    delete(jadid);
    //newChump declaration
    Zombie chuck("chump");
    chuck.randomChump("changed name");
    chuck.announce();
    return(0);
}