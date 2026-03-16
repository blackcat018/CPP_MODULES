#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(const std::string& naw3);
        AMateria(const AMateria& cpy);
        AMateria& operator=(const AMateria& op);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone()const = 0;
        virtual void use(ICharacter& target);
};

#endif