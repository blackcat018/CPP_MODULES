#include "Character.hpp"

Charachter::Charachter(const std::string& smia): name(smia) 
{
     std::cout << "Character constructor called for " << smia << std::endl;
    int i = 0;
    while(i < 4)
    {
        this->inventory[i] = NULL;
        i++;
    }
}
Charachter::Charachter(const Charachter& cpy): name(cpy.name)
{
    
    int i = 0;
    while(i < 4)
    {
        if(cpy.inventory[i])
            this->inventory[i] = cpy.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
        i++;
    }
}

Charachter& Charachter::operator=(const Charachter& op)
{
    int i = 0;
    if(this != &op)
    {
        while(i < 4)
        {
            if(this->inventory[i])
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
            i++;
        }
        i = 0;
        while(i < 4)
        {
            if(op.inventory[i])
                this->inventory[i] = op.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
            i++;
        }
    }
    return(*this);
}

Charachter::~Charachter()
{
    std::cout << "Character destructor called for " << name << std::endl;
    int i = 0;
    while(i < 4)
    {
        delete this->inventory[i];
        i++;
    }
}

std::string const &Charachter::getName()const
{
    return this->name;
}

void Charachter::equip(AMateria *spell)
{
    int i =0;
    if(!spell)
        return;
    while(i < 4)
    {
        if(!this->inventory[i])
        {
            this->inventory[i] = spell;
            return;
        }
            
        i++;
    }
}

void Charachter::unequip(int index)
{
    if(index >=0 && index < 4 && this->inventory[index])
        this->inventory[index] = NULL; 
}

void Charachter::use(int index, ICharacter& target)
{
    if(index >=0 && index < 4 && this->inventory[index])
        this->inventory[index]->use(target);
}
