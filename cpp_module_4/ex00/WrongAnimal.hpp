#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal 
{
    protected:
        std::string wr_type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& cpy);
        WrongAnimal& operator=(const WrongAnimal& op);
        virtual~WrongAnimal();
        void makeSound() const;
        std::string getType() const;
};

#endif