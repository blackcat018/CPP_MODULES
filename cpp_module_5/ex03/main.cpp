#include "Bureaucrat.hpp"
#include "intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed rand() for Robotomy's 50% success/failure chance
    std::srand(std::time(NULL));

    std::cout << "========== 1. INSTANTIATING INTERN & BUREAUCRAT ==========" << std::endl;
    intern    someRandomIntern;
    Bureaucrat boss("Zaphod", 1); // Highest grade (1) to execute any form

    Aform* form1 = NULL;
    Aform* form2 = NULL;
    Aform* form3 = NULL;
    Aform* unknownForm = NULL;

    std::cout << "\n========== 2. INTERN MAKES VALID FORMS ==========" << std::endl;
    form1 = someRandomIntern.makeForm("robotomy request", "Bender");
    form2 = someRandomIntern.makeForm("shrubbery creation", "Garden");
    form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

    std::cout << "\n========== 3. INTERN TRIES INVALID FORM ==========" << std::endl;
    unknownForm = someRandomIntern.makeForm("coffee request", "Boss");
    if (!unknownForm)
    {
        std::cout << "As expected, unknownForm pointer is NULL!" << std::endl;
    }

    std::cout << "\n========== 4. BUREAUCRAT SIGNS AND EXECUTES CREATED FORMS ==========" << std::endl;
    if (form1)
    {
        boss.signForm(*form1);
        boss.executeForm(*form1);
    }

    if (form2)
    {
        boss.signForm(*form2);
        boss.executeForm(*form2);
    }

    if (form3)
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
    }

    std::cout << "\n========== 5. CLEANING UP DYNAMIC MEMORY ==========" << std::endl;
    delete form1;
    delete form2;
    delete form3;
    delete unknownForm; // Safe to delete NULL in C++

    std::cout << "\n========== 6. PROGRAM ENDING ==========" << std::endl;
    return 0;
}