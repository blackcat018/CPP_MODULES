#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Aform
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_exec;
        const int grade_sign;
    public:
        Aform(const std::string &smia, int no9ta_ex, int no9ta_sig);
        Aform(const Aform& cpy);
        Aform& operator=(const Aform& op);
        virtual ~Aform();

        void beSigned(const Bureaucrat &guy);
        std::string get_name() const;
        int get_grade_ex() const;
        int get_grade_sig() const;
        bool get_signe() const;
        virtual void execute(Bureaucrat const &someDude) const = 0;

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
        class FormNotSignedException : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
};


std::ostream& operator<<(std::ostream& out,const Aform &forma);

#endif