#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *dogBrain;
    public:
        Dog();
        Dog(const Dog& cpy);
        Dog& operator=(const Dog& op);
        virtual ~Dog();
        virtual void makeSound() const;
        void setDogIdea(int pos,const std::string& set);
        Brain* getDogBrain()const;
};

#endif