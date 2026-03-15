#ifndef BRAIN_HPP
#define BRAIN_HPP

#include<iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& cpy);
        Brain& operator=(const Brain& op);
        ~Brain();

        void set_idea(int pos ,const std::string& set);
        std::string getIdea(int pos) const;
};

#endif