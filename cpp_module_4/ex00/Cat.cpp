#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "The Cat constructor was just triggered!" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    std::cout << "The Cat COPY Constructor has just triggered!" << std::endl;
}

Cat& Cat::operator=(const Cat& op)
{
    if(this != &op)
    {
        Animal::operator=(op);
    }
    std::cout << "The Cat ASSIGNEMENT COPY constructor was just triggered!" <<std::endl;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "NOOOOOOOO! MY CAT!!! MY SWEET LITTLE CAT IS GONE!" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow 🐱" << std::endl;
}
