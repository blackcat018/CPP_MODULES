#include"Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat : No9ta tal3a bzaf";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat : No9ta habta bzaf asa7bi";
}

Bureaucrat::Bureaucrat(const std::string &smia, int no9ta) : name(smia)
{
    if(no9ta < 1)
        throw GradeTooHighException();
    if (no9ta > 150)
        throw GradeTooLowException();
    this->grade = no9ta;
    std::cout << "DEAFULT construct is done!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name), grade(cpy.grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    else if(grade > 150)
        throw GradeTooLowException();
    std::cout << "COPY construct is done!" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &op)
{
    if(this != &op)
    {
        this->grade = op.get_grade();
    }
    std::cout << "COPY OPERATOR construct is done!" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

int Bureaucrat::get_grade() const
{
    return grade;
}

const std::string Bureaucrat::get_name() const
{
    return name;
}
void Bureaucrat::inrement()
{
    if(grade <= 1)
        throw GradeTooHighException();
    --grade;
}
void Bureaucrat::decrement()
{
    if(grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(Aform& cheet)
{
    try
	{
        cheet.beSigned(*this);
        std::cout << this->name << " signed " << cheet.get_name() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << cheet.get_name() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Aform const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't execute " << form.get_name() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& khadam)
{
	out << khadam.get_name() << ", bureaucrat grade " << khadam.get_grade();
	return out;
}