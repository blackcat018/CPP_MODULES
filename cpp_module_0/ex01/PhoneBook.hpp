#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		contact contacts[LAST];
		int stored_contacts;
		int track;
        int s_index;
		
	public:
		PhoneBook();
        void search_contact();
        void print_greetings();
		void add_contact();
		void display_all();
		void display_contat();
};

#endif