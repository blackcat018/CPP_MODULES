#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound(); // Cat sound
    j->makeSound(); // Dog sound
    meta->makeSound(); // Animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n---- Wrong Animal Test ----\n" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "the type of wrong Cat  is : " << wrongCat->getType() << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "printing the wrong CAT sound : ";
    wrongCat->makeSound();
    std::cout << std::endl;
    std::cout << "printing the wrong ANIMAL sound : ";
    wrongMeta->makeSound();
std::cout << "============================" << std::endl;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}