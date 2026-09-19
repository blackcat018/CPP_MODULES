#include "span.hpp"

int main()
{
    std::cout << "---------------------- Normal Test ---------------------- \n" <<std::endl;
    try{   
        span sp(3);
        sp.addNumber(15);
        sp.addNumber(2);
        sp.addNumber(29);
        std::cout << "the longest span is : " << sp.longestSpan() << std::endl;
        std::cout << "the shortest span is : " << sp.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }

    std::cout << "\n---------------------- Full Span test ---------------------- \n" << std::endl;
    try{   
        span sp(3);
        sp.addNumber(15);
        sp.addNumber(2);
        sp.addNumber(29);
        sp.addNumber(2134);
        sp.addNumber(324);
        std::cout << "the longest span is : " << sp.longestSpan() << std::endl;
        std::cout << "the shortest span is : " << sp.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }
    std::cout << "\n---------------------- Span is less that 2 test ---------------------- \n" << std::endl;
        try{   
        span sp(1);
        sp.addNumber(15);
        std::cout << "the longest span is : " << sp.longestSpan() << std::endl;
        std::cout << "the shortest span is : " << sp.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }
    std::cout << "\n---------------------- 10'000 elements test ---------------------- \n" << std::endl;

    try{
        std::vector<int> tmp ;
        tmp.reserve(10000);
        std::srand(std::time(0));
        for(int i = 0; i < 10000;i++)
        {
            tmp.push_back(std::rand());
        }
        span sp(10000);
        sp.addBatch(tmp.begin(),tmp.end());
        std::cout << "To make sure we added 10K elements, the size of the container is : " << sp.get_size() << std::endl;
        std::cout << "the longest span is : " << sp.longestSpan() << std::endl;
        std::cout << "the shortest span is : " << sp.shortestSpan() << std::endl;
        std::cout << "to make sure the min and max are correct for the longest span :" << std::endl;
        sp.print_minMax();
    }
    catch(std::exception &e)
    {
        std::cout << "Exception : " << e.what() << std::endl; 
    }
    return 0;
}