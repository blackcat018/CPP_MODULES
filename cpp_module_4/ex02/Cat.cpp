#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->catBrain = new Brain();
    std::cout << "The Cat constructor was just triggered!" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    this->catBrain = new Brain(*cpy.catBrain);
    std::cout << "The Cat COPY Constructor has just triggered!" << std::endl;
}

Cat& Cat::operator=(const Cat& op)
{
    if(this != &op)
    {
        Animal::operator=(op);
        delete this->catBrain;
        this->catBrain = new Brain(*op.catBrain);
    }
    std::cout << "The Cat ASSIGNEMENT COPY constructor was just triggered!" <<std::endl;
    return(*this);
}

Cat::~Cat()
{
    delete this->catBrain;
    std::cout << "NOOOOOOOO! MY CAT!!! MY SWEET LITTLE CAT IS GONE!" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meow 🐱" << std::endl;
}

void Cat::setCatIdea(int pos, const std::string& str)
{
    this->catBrain->set_idea(pos,str);
}

Brain* Cat::getCatBrain() const
{
    return(this->catBrain);
}