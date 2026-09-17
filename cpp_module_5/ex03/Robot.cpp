#include "Robot.hpp"

robot::robot(const std::string &hadaf): Aform("Create Robotomy Request Form: ",45,72), target(hadaf)
{
    std::cout << "DEFAULT ROBOTOMY CONSTRUCTOR IS DONE!" << std::endl;
}

robot::robot(const robot &cpy): Aform(cpy), target(cpy.target)
{
    std::cout << "COPY ROBOTOMY CONSTRUCTOR IS DONE!" << std::endl;
}
robot &robot::operator=(const robot&op)
{
    if(this != &op)
    {
        Aform::operator=(op);
        this->target = op.target;
    }
    std::cout << "COPY OPERATOR ROBOTOMY CONSTRUCTOR IS DONE!" << std::endl;
    return *this;
}

robot::~robot() {}

void robot::execute(Bureaucrat const &executor) const
{
    if(!this->get_signe())
        throw Aform::FormNotSignedException();
    if(executor.get_grade() > this->get_grade_ex())
        throw Aform::GradeTooLowException();
    std::cout << "bzzzt... bzzzt, eeee-errr-dok" <<std::endl;
    if (rand() % 2 == 0)
        std::cout << "OH MY GOD! IT'S A MIRACLE! " << this->target << " HAS BEEN ROBOTOMIZED SUCCESSFULLY!!!" << std::endl;
    else
        std::cout << "The robotomy on " << this->target << " has failed! Fire whoever is responsible for this!" << std::endl;
}