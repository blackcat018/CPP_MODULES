#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include<iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *matter[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& cpy);
        MateriaSource& operator=(const MateriaSource& op);
        ~MateriaSource();
        virtual void learnMateria(AMateria* mat);
        virtual AMateria* createMateria(std::string const & chemical);
};
#endif