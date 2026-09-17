#include "AForm.hpp"

const char* Aform::GradeTooHighException:: what() const throw()
{
    return "the grade is too damn high! take it down a notch bro!";
}

const char* Aform::GradeTooLowException:: what() const throw()
{
    return "the grade is waaay to low! you cannot go below 150!";
}

const char* Aform::FormNotSignedException:: what() const throw()
{
    return "The Form is not signed!";
}

Aform::Aform(const std::string &smia, int no9taE, int no9taS) : name(smia), grade_exec(no9taE), grade_sign(no9taS)
{
    if(grade_exec < 1 || grade_sign < 1)
        throw GradeTooHighException();
    else if(grade_exec > 150 || grade_sign > 150)
        throw GradeTooLowException();
    is_signed = false;
    std::cout<< "---DEFAULT CONSTRUCTIONS ID DONE!---" << std::endl;
}
Aform::Aform(const Aform& cpy) : name(cpy.name), grade_exec(cpy.grade_exec), grade_sign(cpy.grade_sign)
{
    //no need to throw exeprions here because we copy from an alredy established form
    std::cout<< "---COPY CONSTRUCTIONS ID DONE!---" << std::endl;
}

Aform& Aform::operator=(const Aform& op)
{
    if(this != &op)
        this->is_signed = op.is_signed;
    std::cout<< "---COPY OPERATOR CONSTRUCTIONS ID DONE!---" << std::endl;
    return(*this);
}

Aform::~Aform(){}


void Aform::beSigned(Bureaucrat const &b)
{
    if (b.get_grade() > this->get_grade_sig())
        throw Aform::GradeTooLowException();
    this->is_signed = true;
}

std::string Aform::get_name() const
{
    return(name);
}

int Aform::get_grade_ex() const
{
    return(grade_exec);
}

int Aform::get_grade_sig() const
{
    return(grade_sign);
}

bool Aform::get_signe() const
{
    return(is_signed);
}

std::ostream& operator<<(std::ostream& out,const Aform &cheet)
{
    out << "Form : " << cheet.get_name() << "\n"
        << "Signed : " << (cheet.get_signe() ? "yes":"no") << "\n"
        << "grade to allow signing : " << cheet.get_grade_ex() << "\n"
        << "grade to do execution : " << cheet.get_grade_sig();
    return out;
}
