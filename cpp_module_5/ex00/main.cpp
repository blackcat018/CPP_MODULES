#include "Bureaucrat.hpp"

int main()
{
    try
	{
		Bureaucrat obj("Idou", 2);
		std::cout << obj << std::endl;
		obj.inrement();
		std::cout << obj << std::endl;
		obj.decrement();
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}