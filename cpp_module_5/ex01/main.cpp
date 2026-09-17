#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat executive("Mohamed",3);
		Bureaucrat intern("wiam",149);
		Form waterBill("water bill",50,10);
		std::cout << " " << std::endl;
		std::cout << "----- the Form -----" << std::endl;
		std::cout << waterBill << "\n" << std::endl;


		std::cout << "----- the Form signed by the intern-----"<< std::endl;
		intern.signForm(waterBill);
		std::cout << waterBill << "\n" << std::endl;

		std::cout << "----- the Form signed by the Executive-----"<< std::endl;
		executive.signForm(waterBill);
		std::cout << waterBill << "\n" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout<< "Exception: " << e.what() <<std::endl;
	}
	return(0);
}