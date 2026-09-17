#include "President.hpp"

president::president(const std::string &hadaf): Aform("Create Presidency Request Form: ",5,25), target(hadaf)
{
    std::cout << "DEFAULT PRESIDENCY CONSTRUCTOR IS DONE!" << std::endl;
}

president::president(const president &cpy): Aform(cpy), target(cpy.target)
{
    std::cout << "COPY PRESIDENCY CONSTRUCTOR IS DONE!" << std::endl;
}
president &president::operator=(const president&op)
{
    if(this != &op)
    {
        Aform::operator=(op);
        this->target = op.target;
    }
    std::cout << "COPY OPERATOR PRESIDENCY CONSTRUCTOR IS DONE!" << std::endl;
    return *this;
}

president::~president(){}

void president::execute(Bureaucrat const &executor) const
{
    if(!this->get_signe())
        throw Aform::FormNotSignedException();
    if(executor.get_grade() > this->get_grade_ex())
        throw Aform::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}