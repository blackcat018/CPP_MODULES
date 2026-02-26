#include "Contact.hpp"

void contact::set_informations()
{
	int i = 0;
	std::cout << "Please type in your name : " << std::endl;
	if(!std::getline(std::cin , FirstName))
		return;
	if(FirstName == "")
	{
		std::cout << "You forgot to add a firstname!" << std::endl;
		return;
	}
	std::cout << "Please type in your surname : " << std::endl;
	if(!std::getline(std::cin , LastName))
		return;
	if(LastName == "")
	{
		std::cout << "You forgot to add a lastname!" << std::endl;
		FirstName.clear();
		return;
	}
	std::cout << "Please type in your Phone number : " << std::endl;
	if(!std::getline(std::cin,PhoneNumber))
		return;
	if(PhoneNumber == "")
	{
		std::cout << "You forgot to add a Phone number!" << std::endl;
		FirstName.clear();
		LastName.clear();
		return;
	}
	while(PhoneNumber[i])
	{
		if(!isdigit(PhoneNumber[i]))
		{
			FirstName.clear();
			LastName.clear();
			PhoneNumber.clear();
			std::cout << "The phone number you entered contains a non digit charachter! Please try to ADD again!";
			std::cout << std::endl;
			return;
		}
		i++;
	}
	std::cout << "\nThe contact wad added successfully! Endter the SHOW command to view your contact list!";
	std::cout << std::endl;
}

void contact::print_info_header()
{
	std::cout << "Your informations are -> " << std::endl;
    std::cout << "|" << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name"  << "|";
	std::cout << std::setw(12) << std::right << "PhoneNumber" << "|";
	std::cout << std::endl;

}

void contact::print_info(int index)
{
    std::cout << "|" << std::setw(10) << std::right << index ;

	std::string displayFirst = get_name();
	if (displayFirst.length() > 10)
		displayFirst = displayFirst.substr(0, 9) + ".";
	std::cout << "|" << std::setw(10) << std::right << displayFirst;

	displayFirst = get_surname();
	if (displayFirst.length() > 10)
		displayFirst = displayFirst.substr(0, 9) + ".";
	std::cout << "|" << std::setw(10) << std::right << displayFirst;

	displayFirst = get_number();
	if (displayFirst.length() > 10)
		displayFirst = displayFirst.substr(0, 9) + ".";
	std::cout << "|" << std::setw(12) << std::right << displayFirst << "|";
	std::cout << std::endl;
}

std::string contact::get_name()
{
    return(FirstName);
}
std::string contact::get_surname()
{
    return(LastName);
}
std::string contact::get_number()
{
    return(PhoneNumber);
}
