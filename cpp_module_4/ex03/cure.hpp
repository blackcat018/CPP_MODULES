#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        Cure(const Cure& cpy);
        Cure& operator=(const Cure& op);
        ~Cure();
        virtual void use(ICharacter& target);
        virtual AMateria* clone() const;
};

#endif