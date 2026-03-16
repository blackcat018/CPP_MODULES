#include "AMateria.hpp"

AMateria::AMateria(const std::string& naw3) : type(naw3)
{
    std::cout<< "AMATERIA Default constructor!" << std::endl;
}

AMateria::AMateria(const AMateria& cpy) : type(cpy.type)
{
    std::cout << "AMATERIA Copy constructor!" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& op)
{
    if(this != &op)
       //Nada! Walo! Rien! Nothing!
    std::cout << "ASSIGNEMENT Constructor for the Amateria" << std::endl;
    return(*this);
}

std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria::~AMateria()
{
    std::cout << "Distructor!" << std::endl;
}
void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "A spell was Cast at " << std::endl;
}