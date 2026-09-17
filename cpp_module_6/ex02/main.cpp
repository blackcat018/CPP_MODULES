#include "Core.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "--- Test " << i + 1 << " ---" << std::endl;
        
        base* ptr = generate();

        std::cout << "Pointer identify:   ";
        identify(ptr);

        std::cout << "Reference identify: ";
        identify(*ptr);

        delete ptr;
        std::cout << std::endl;
    }

    return 0;
}