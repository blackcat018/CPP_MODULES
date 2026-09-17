#include "Shrubbery.hpp"

shrubb::shrubb(const std::string &goal): Aform("Created Shrubbery: ",137,145), target(goal)
{
    std::cout << "DEFAULt Shrubbery FROM Creted!" << std::endl;
}

shrubb::shrubb(const shrubb& cpy): Aform(cpy), target(cpy.target)
{
    std::cout << "COPY Shrubbery FROM Creted!" << std::endl;
}

shrubb& shrubb::operator=(const shrubb& op)
{
    
    if(this != &op)
    {
        Aform::operator=(op);
        this->target = op.target;
    }
    std::cout << "COPY OPERATOR Shrubbery FROM Creted!" << std::endl;
    return(*this);
}

void shrubb::execute(Bureaucrat const &executor) const
{
    if(!this->get_signe())
        throw Aform::FormNotSignedException();
    if(executor.get_grade() > this->get_grade_ex())
        throw Aform::GradeTooLowException();
    std::string filename = this->target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if(!outfile.is_open())
    {
        std::cerr << "ERROR! THE FILE COULD NOT OPEN!" <<std::endl;
        return;
    }
    outfile << "               ,@@@@@@@,\n"
            << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\8888'\n"
            << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            << "       |o|        | |         | |\n"
            << "       |.|        | |         | |\n"
            << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outfile.close();
}

shrubb::~shrubb(){};
