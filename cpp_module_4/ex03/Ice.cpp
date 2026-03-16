#include "Ice.hpp"

Ice::Ice() : AMateria("ice") 
{
    std::cout << "-- ICE 🧊 DEFAULT CONSTRUCTOR! --" << std::endl;
}

Ice::Ice(const Ice& cpy) : AMateria(cpy)
{
    std::cout << "-- ICE 🧊 COPY CONSTRUCTOR --" << std::endl;
}

Ice& Ice::operator=(const Ice& op)
{
    if(this != &op)
        AMateria::operator=(op);
    std::cout << "-- ICE 🧊 ASSIGNEMENT CONSTRUCTOR --" << std::endl;
    return(*this);
}

Ice::~Ice()
{
    std::cout << "-- DESTROYE THE ICE 🧊 --" << std::endl;
}

AMateria* Ice::clone() const
{
    return(new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}