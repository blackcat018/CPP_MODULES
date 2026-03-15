#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->wr_type = "Wrong Cat";
    std::cout << "the Wrong Cat's Default constructor was just triggered!" << std::endl;
}
WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy)
{
    std::cout<< "The Wrong Cat COPY Constructor was just triggered!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& op)
{
    if(this != &op)
        WrongAnimal::operator=(op);
    std::cout << "the Wrong Cat ASSIGNEMENT COPY constructor was just triggered!" << std::endl;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "the thing that is not a cat is DEAD!" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Not Meow Not Meow!" << std::endl;
}