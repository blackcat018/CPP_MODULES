#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : wr_type("Wrong Animal")
{
    std::cout << "the wrong animal default constructor was just triggered!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy) : wr_type(cpy.wr_type)
{
    std::cout << "The wrong Animal COPY constructor was just triggered!" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& op)
{
    if(this != &op)
        this->wr_type = op.getType();
    std::cout << "The wrong Animal ASSIGNEMENT COPY constructor was just triggered!" << std::endl;
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "I do not know what that thing was but it just DIED! ... rip?" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "This is The Wrong Animal's Sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(wr_type);
}