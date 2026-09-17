#include "Core.hpp"

// base * generate(void);
// void identify(base* p);
// void identify(base& p);

base * generate(void)
{
    int result = rand() % 3 + 1;
    switch (result)
    {
    case 0:
        return new a;
    case 1:
        return new b;
    default:
        return new c;
    }
}

void identify(base* p)
{
    if(dynamic_cast<a*>(p))
        std::cout << "The type of the variable is: A" << std::endl;
    else if(dynamic_cast<b*>(p))
         std::cout << "The type of the variable is: B" << std::endl;
    else if(dynamic_cast<c*>(p))
         std::cout << "The type of the variable is: C" << std::endl;
    else
         std::cout << "Bro! what is the world did you just give me to inspect?!" << std::endl;

}

void identify(base& p)
{
    try
    {
        (void)dynamic_cast<a&>(p);
        std::cout << "The type of the variable is: A" << std::endl;
        return;
    }
    catch(std::exception&){}
    try
    {
        (void)dynamic_cast<b&>(p);
        std::cout << "The type of the variable is: B" << std::endl;
        return;
    }
    catch(std::exception&){}
    try
    {
        (void)dynamic_cast<c&>(p);
        std::cout << "The type of the variable is: C" << std::endl;
        return;
    }
    catch(std::exception&){}
}