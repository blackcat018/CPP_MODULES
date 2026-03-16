#ifndef CHARACHTER_HPP
#define CHARACHTER_HPP

#include"ICharacter.hpp"
#include"AMateria.hpp"

class Charachter: public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Charachter(const std::string& smia);
        Charachter(const Charachter& cpy);
        Charachter& operator=(const Charachter& op);
        virtual ~Charachter();
        virtual std::string const & getName() const ;
        virtual void equip(AMateria* spell);
        virtual void unequip(int index);
        virtual void use(int index, ICharacter& target);
};

#endif