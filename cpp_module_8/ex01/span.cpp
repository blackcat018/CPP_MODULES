#include "span.hpp"

span::span()
{
    N = 0;
    std::cout << "the default constructor is done!" << std::endl;
}

span::span(const unsigned int C) : N(C)
{
    std::cout << "the const constructor is done!" << std::endl;
}

span::span(const span &cpy): N(cpy.N)
{
    std::cout << "the copy Constructor is done!" << std::endl;
}

span& span::operator=(const span&op)
{
    if(this != &op)
    {
        this->N = op.N;
    }
    std::cout << "the operator assignement constructor is done!" << std::endl;
    return *this;
}

span::~span(){}

void span::addNumber(const unsigned int number)
{
    if(arr.size() >= N)
        throw fullSpanException();
    arr.push_back(number);
}

unsigned int span::longestSpan() const
{
    if(arr.size() < 2)
    {
        throw noSpanException();
    }
    std::vector<int>::const_iterator min = std::min_element(arr.begin(), arr.end());
    std::vector<int>::const_iterator max = std::max_element(arr.begin(),arr.end());
    unsigned int dist = (static_cast<long>(*max) - static_cast<long>(*min));
    return dist;
}

int span::get_size() const
{
    return(arr.size());
}

void span::print_minMax() const
{
    std::vector<int>::const_iterator min = std::min_element(arr.begin(), arr.end());
    std::vector<int>::const_iterator max = std::max_element(arr.begin(),arr.end());
    std::cout << "the min is : " << *min << std::endl;
    std::cout << "the max is : " << *max << std::endl;
}

unsigned int span::shortestSpan() const
{
    if(arr.size() < 2)
    {
        throw noSpanException();
    }
    std::vector <int> tmp = arr;
    std::sort(tmp.begin(), tmp.end());
    unsigned int i = 0;
    unsigned int diff = static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i]);
    i = 1;
    while(i < tmp.size() - 1)
    {
        if(diff > (static_cast<long>(tmp[i + 1] )- static_cast<long>(tmp[i])))
            diff = static_cast<long>(tmp[i + 1]) - static_cast<long>(tmp[i]);
        i++;
    }
    return (diff);
}

