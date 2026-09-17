#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat 
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(const std::string &smia,int no9ta);
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat& operator=(const Bureaucrat& op);
        ~Bureaucrat();
        const std::string get_name() const;
        int get_grade() const;
        void inrement();
        void decrement();
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif