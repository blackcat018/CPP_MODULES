#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Aform;
class Bureaucrat;

class robot : public Aform
{
    private:
        std::string target;
    public:
        robot(const std::string &hadaf);
        robot(const robot& cpy);
        robot& operator=(const robot& op);
        ~robot();
        virtual void execute(Bureaucrat const &executor) const;
};


#endif