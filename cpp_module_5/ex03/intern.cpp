#include "intern.hpp"

intern::intern()
{
    std::cout << "An Intern has joined the bureau!" << std::endl;
}

intern::intern(const intern &cpy)
{
    (void)cpy;
    std::cout << "An Intern has been cloned!" << std::endl;
}

intern &intern::operator=(const intern &op)
{
    (void)op;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

intern::~intern()
{
    std::cout << "An Intern has left the bureau!" << std::endl;
}

Aform* intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string existingForms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int index = -1;
    for (int i = 0; i < 3; i++)
    {
        if (formName == existingForms[i])
        {
            index = i;
            break;
        }
    }

    switch (index)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return new shrubb(target);
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return new robot(target);
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return new president(target);
        default:
            std::cerr << "Error: Intern cannot create '" << formName 
                      << "' because it does not exist!" << std::endl;
            return NULL;
    }
}