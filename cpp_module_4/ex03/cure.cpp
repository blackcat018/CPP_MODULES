#include "cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "-- CURE 🧪 DEFAULT CONSTRUCTOR! --" << std::endl;
}

Cure::Cure(const Cure& cpy) : AMateria(cpy) 
{
    std::cout << "-- CURE 🧪 COPY CONSTRUCTOR --" << std::endl;
}

Cure& Cure::operator=(const Cure& op)
{
    if(this != &op)
    {
        AMateria::operator=(op);
    }
    std::cout << "-- CURE 🧪 ASSIGNEMENT CONSTRUCTOR --" << std::endl;
    return(*this);
}

Cure::~Cure()
{
    std::cout << "-- DESTROYE THE CURE 🧪 --" << std::endl;
}

AMateria* Cure::clone() const
{
    return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals "<< target.getName() << "'s wounds *" <<std::endl;
}