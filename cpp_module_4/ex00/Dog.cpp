#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "The Dog constructor has just triggered!" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
    std::cout << "the Dog COPY constructor has just triggered!" << std::endl; 
}

Dog& Dog::operator=(const Dog& op)
{
    if(this != &op)
        Animal::operator=(op);
    std::cout << "The Dog ASSIGNEMENT COPY constructor has just triggered!" << std::endl;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "the dog is dead I guess 😒" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof 🐶" << std::endl;
}