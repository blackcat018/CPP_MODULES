#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Shrubbery.hpp"
#include "Robot.hpp"
#include "President.hpp"




class intern
{
    public:
        intern();
        intern(const intern &cpy);
        intern &operator=(const intern& intern);
        ~intern();

        Aform* makeForm(const std::string &formName, const std::string &target);
};

#endif