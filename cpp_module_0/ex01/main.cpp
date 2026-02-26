#include "PhoneBook.hpp"

int main (int ac, char **av)
{
	if(ac > 1)
		return 1;
	(void)av;
	(void)ac;
	PhoneBook info;
	std::string command;
	info.print_greetings();
	while(true)
	{
		if (!std::getline(std::cin, command))
    		break;
		if(command == "ADD")
			info.add_contact();
		else if(command == "EXIT")
			break;
		else if(command == "SHOW")
			info.display_all();
		else if(command == "SEARCH")
		{
			info.display_all();
			info.search_contact();
		}
		else if(command == "")
			std::cout << "please enter a command!" << std::endl;
		else
		{
			std::cout << " the command you entered does not exist! " << std::endl;
		}
	}
	
	return(0);
}