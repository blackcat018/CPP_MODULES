#include "whatever.hpp"

int main()
{
    std::cout << "------------------- SWAP TEST -------------------" << std::endl;
    int a = 15;
    int b = 21031;
    std::cout << "\nthe value of a is : " << a  << "\nthe value of b is: " << b << std::endl;
    swap(a,b);
    std::cout << "\nthe value of a is : " << a  << "\nthe value of b is: " << b << std::endl;
    std::cout << "\n------------------- MIN TEST -------------------" << std::endl;
    std::cout << "the min of a : " << a << " and b : " << b << " is : " << min(a,b) << std::endl;
    std::cout << "\n------------------- MAX TEST -------------------" << std::endl;
    std::cout << "the max of a : " << a << " and b : " << b << " is : " << max(a,b) << std::endl;
    return 0;
}