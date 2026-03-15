#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "----- Animal Array Test -----" << std::endl;

    const Animal* animals[4];
    int i = 0;

    while (i < 2)
    {
        animals[i] = new Dog();
        i++;
    }

    while (i < 4)
    {
        animals[i] = new Cat();
        i++;
    }

    i = 0;
    while (i < 4)
    {
        animals[i]->makeSound();
        i++;
    }

    i = 0;
    while (i < 4)
    {
        delete animals[i];
        i++;
    }

    std::cout << "\n----- Deep Copy Test -----" << std::endl;

    Dog original;
    original.getDogBrain()->set_idea(0, "I want a bone");

    Dog copy(original);

    std::cout << "Original idea: "
              << original.getDogBrain()->getIdea(0) << std::endl;

    std::cout << "Copy idea: "
              << copy.getDogBrain()->getIdea(0) << std::endl;

    std::cout << "\nChanging original idea...\n";

    original.getDogBrain()->set_idea(0, "I want a steak");

    std::cout << "Original idea: "
              << original.getDogBrain()->getIdea(0) << std::endl;

    std::cout << "Copy idea: "
              << copy.getDogBrain()->getIdea(0) << std::endl;

    return 0;
}