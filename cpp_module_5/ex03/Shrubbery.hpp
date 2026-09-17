#ifndef SHRUBERY_HPP
#define SHRUBERY_HPP
#include "AForm.hpp"
#include <fstream>
#include "Bureaucrat.hpp"

class Aform;
class Bureaucrat;

class shrubb : public Aform
{
    private:
        std::string target;
    public:
        shrubb(const std::string &hadaf);
        shrubb(const shrubb& cpy);
        shrubb& operator=(const shrubb& op);
        ~shrubb();
        virtual void execute(Bureaucrat const &executor) const;
        // the execute methode shall be added at a later time my liege

};

#endif