#include "Bureaucrat.hpp"

int main()
{
    try
	{
		Bureaucrat obj("Idou", 2);
		std::cout << "the original state! : " << obj << std::endl;
		obj.inrement();
		std::cout << "After incrementing : " << obj << std::endl;
		obj.decrement();
		std::cout << "After decrementing : " << obj << std::endl;
		std::cout << "\n--------- testing exception ---------" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}