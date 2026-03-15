#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->dogBrain = new Brain();
    std::cout << "The Dog constructor has just triggered!" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy)
{
    this->dogBrain = new Brain(*cpy.dogBrain);
    std::cout << "the Dog COPY constructor has just triggered!" << std::endl; 
}

Dog& Dog::operator=(const Dog& op)
{
    if(this != &op)
    {
        Animal::operator=(op);
        delete this->dogBrain;
        this->dogBrain = new Brain(*op.dogBrain);
    }
    std::cout << "The Dog ASSIGNEMENT COPY constructor has just triggered!" << std::endl;
    return(*this);
}

Dog::~Dog()
{
    delete this->dogBrain;
    std::cout << "the dog is dead I guess 😒" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof 🐶" << std::endl;
}

void Dog::setDogIdea(int pos,const std::string& set)
{
    this->dogBrain->set_idea(pos,set);
}

Brain* Dog::getDogBrain()const
{
    return(this->dogBrain);
}