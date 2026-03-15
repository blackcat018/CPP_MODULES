#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "The Brain Default Constructor has just Triggered!" << std::endl;
    int  i = 0;
    while(i < 100)
    {
        this->ideas[i] = "Lobotomized";
        i++;
    }
}

Brain::Brain(const Brain& cpy)
{
    std::cout << "The Brain COPY Constructor hass just triggered!" << std::endl;
    int i = 0;
    while(i < 100)
    {
        this->ideas[i] = cpy.ideas[i];
        i++;
    }
}

Brain& Brain::operator=(const Brain& op)
{
    if(this != &op)
    {
        int i = 0;
        while(i < 100)
        {
            this->ideas[i] = op.ideas[i];
            i++;
        }
    }
    std::cout << "The Brain ASSIGNEMENT COPY Constructor hass just triggered!" << std::endl;
    return(*this);
}

Brain::~Brain()
{
    std::cout<< "Flat Line! the BRIAN IS DEAD!!!! Harvest the other Organs for donation!" << std::endl;
}

void Brain::set_idea(int pos ,const std::string& set)
{
    if(pos >=0 && pos < 100)
        this->ideas[pos] = set;
}

std::string Brain::getIdea(int pos) const
{
    if(pos >=0 && pos < 100)
        return(this->ideas[pos]);
    return("Error!");
}
