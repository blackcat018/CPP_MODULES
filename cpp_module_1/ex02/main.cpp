#include <iostream>

int main()
{
    std::string str =  "HI THIS IS BRAIN";

    //pointer
    std::string *stringPTR  = &str;

    //reference
    std::string& stringREF = str;

    //adresses
    std::cout << "the adress of the original string is : " << &str << std::endl;
    std::cout << "the adress of the pointer to the string is : " << stringPTR << std::endl;
    std::cout << "the adress of the reference is : " << &stringREF << std::endl;
    std::cout << std::endl;
    
    //values
    std::cout << "the value of the original string is : " << str << std::endl;
    std::cout << "the value of the pointer is : " << *stringPTR << std::endl;
    std::cout << "the value of the reference is : " << stringREF << std::endl;
    return(0);
}