#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define LAST 8

class contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string PhoneNumber;
	public:
		void set_informations();
		void print_info_header();
		void print_info(int index);
        std::string get_name();
        std::string get_surname();
        std::string get_number();
};



#endif