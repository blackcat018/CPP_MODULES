#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form : No9ta tal3a bzaf";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form : No9ta habta bzaf asa7bi";
}

Form::Form(const std::string &smia, int no9taE, int no9taS) : name(smia), grade_exec(no9taE), grade_sign(no9taS)
{
    is_signed = false;
    if(no9taE < 1 || no9taS < 1)
        throw GradeTooHighException();
    if(no9taE > 150 || no9taS > 150)
        throw GradeTooLowException();
    std::cout << "====THE FORM STANDARD CONSTRUCTION IS DONE!===="<< std::endl;
}
Form::Form(const Form& cpy) : name(cpy.name), grade_exec(cpy.grade_exec), grade_sign(cpy.grade_sign)
{
    if(grade_exec < 1 || grade_sign < 1)
        throw GradeTooHighException();
    if(grade_exec > 150 || grade_sign > 150)
        throw GradeTooLowException();
    std::cout << "====THE FORM COPY CONSTRUCTION IS DONE!====" << std::endl;
}

Form& Form::operator=(const Form& op)
{
    if(this != &op)
    {
        this->is_signed = op.is_signed;
    }
    std::cout << "====THE FORM OPERATOR COPY CONSTRUCTOR IS DONE!====" << std::endl;
    return *this;
}

Form::~Form(){}

void Form::beSigned(const Bureaucrat& guy)
{
    if(guy.get_grade() <= grade_sign)
        is_signed = true;
    else
        throw GradeTooLowException();
}

std::string Form::get_name() const
{
    return(name);
}

int Form::get_grade_ex() const
{
    return(grade_exec);
}

int Form::get_grade_sig() const
{
    return(grade_sign);
}

bool Form::get_signe() const
{
    return(is_signed);
}

std::ostream& operator<<(std::ostream& out,const Form &cheet)
{
    out << "Form : " << cheet.get_name() << "\n"
        << "Signed : " << (cheet.get_signe() ? "yes":"no") << "\n"
        << "grade to allow signing : " << cheet.get_grade_ex() << "\n"
        << "grade to do execution : " << cheet.get_grade_sig();
    return out;
}