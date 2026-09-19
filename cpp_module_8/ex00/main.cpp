#include "Easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> container;
    container.push_back(69);
    container.push_back(420);
    container.push_back(67);
    container.push_back(21);
    try
    {
        easyfind(container,67);
        std::cout<< "Found 67 in the container! " << std::endl;
    }
    catch(std::exception&e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
        try
    {
        easyfind(container,11);
        std::cout<< "Found the 11 in the container! " << std::endl;
    }
    catch(std::exception&e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
        try
    {
        easyfind(container,420);
        std::cout<< "Found the 420 in the container! " << std::endl;
    }
    catch(std::exception&e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}