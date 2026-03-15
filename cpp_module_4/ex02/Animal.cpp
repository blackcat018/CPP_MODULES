#include "Animal.hpp"

Animal::Animal () :type("Animal")
{
    std::cout << "Animal Constructor was just triggered" <<std::endl;
}
Animal::Animal(const Animal& cpy) : type(cpy.type)
{
    std::cout << "Animal COPY Constructor was just triggered" <<std::endl;
}
Animal& Animal::operator=(const Animal& op)
{
    if(this != &op)
    {
        this->type = op.getType();
    }
    std::cout << "Animal COPY ASSIGNEMENT Constructor was just triggered" <<std::endl;
    return(*this);
}
Animal::~Animal()
{
    std::cout << "the Animal is DEAD! IT DIED! YOU KILLED MY ANIMAL YOU MONSTER!" << std::endl;
}

std::string Animal::getType() const
{
    return(type);
}