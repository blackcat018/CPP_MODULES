#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
    private:
        Brain *catBrain;
    public:
        Cat();
        Cat(const Cat& cpy);
        Cat& operator=(const Cat& op);
        virtual ~Cat();
        virtual void makeSound() const;
        Brain* getCatBrain() const;
        void setCatIdea(int pos,const std::string& str);
};

#endif