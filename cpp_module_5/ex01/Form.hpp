#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_exec;
        const int grade_sign;
    public:
        Form(const std::string &smia, int no9ta_ex, int no9ta_sig);
        Form(const Form& cpy);
        Form& operator=(const Form& op);
        ~Form();

        void beSigned(const Bureaucrat &guy);
        std::string get_name() const;
        int get_grade_ex() const;
        int get_grade_sig() const;
        bool get_signe() const;

        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out,const Form &forma);

#endif