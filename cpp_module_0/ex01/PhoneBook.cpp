#include "PhoneBook.hpp"

void PhoneBook::print_greetings()
{
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "  📞✨ WELCOME, MASTER OF CONTACTS! ✨📞\n";
    std::cout << "=========================================\n\n";

    std::cout << " Choose your command:\n\n";

    std::cout << "  ADD   - Forge a new connection\n";
    std::cout << "  SHOW  - Reveal the sacred list\n";
    std::cout << "  SEARCH - Search for your sworn enemy in the list\n";
    std::cout << "  EXIT  - Vanish into the digital void\n\n";

    std::cout << " Your move:\n";
}

PhoneBook::PhoneBook()
{
	track = 0;
	stored_contacts = 0;
}

void PhoneBook::display_all()
{
	if(stored_contacts == 0)
		std::cout << std::setw(10) << std::left << "You have no contacts registered! please use the ADD command to add one!" << std::endl;
	if (stored_contacts!= 0)
     contacts[0].print_info_header();
    for (int i = 0; i < stored_contacts; i++)
        contacts[i].print_info(i);
}

void PhoneBook::add_contact()
{
	contacts[track % LAST].set_informations();
    if(contacts[track % LAST].get_name() == ""
        || contacts[track % LAST].get_surname() == ""
        || contacts[track % LAST].get_number() == "")
        return;
		(track)++;
	if(stored_contacts < LAST)
		(stored_contacts)++;
	
}

void PhoneBook::search_contact()
{
    if(track == 0)
        return;
    std::cout << "Please enter the Index if the contact you want to view : ";
    std::string line;
    if(!std::getline(std::cin, line))
        return;
    int i = 0;
    while(line[i])
    {
        if(!isdigit(line[i]))
        {
            std::cout << "bruh! I said enter a number, a positive number!" << std::endl;
            return;
        }
        i++;
    }
    s_index = std::stoi(line);
    if(s_index < 0 || s_index >= stored_contacts)
    {
        std::cout << "the index you entered in invalid!" <<std::endl;
        return;
    }
    std::cout << std::endl;
    std::cout << "First Name :" << contacts[s_index].get_name() << std::endl;
    std::cout << "Last Name : " << contacts[s_index].get_surname() << std::endl;
    std::cout << "Phone Number : " << contacts[s_index].get_number() << std::endl;
}