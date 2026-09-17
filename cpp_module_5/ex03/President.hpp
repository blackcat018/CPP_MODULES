#ifndef PRESIDENT_HPP
#define PRESIDENT_HPP
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Aform;
class Bureaucrat;

class president : public Aform
{
    private:
        std::string target;
    public:
        president(const std::string &hadaf);
        president(const president& cpy);
        president& operator=(const president& op);
        ~president();
        virtual void execute(Bureaucrat const &executor) const;
};


#endif